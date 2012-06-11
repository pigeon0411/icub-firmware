/*
 * Copyright (C) 2011 Department of Robotics Brain and Cognitive Sciences - Istituto Italiano di Tecnologia
 * Author:  Valentina Gaggero
 * email:   valentina.gaggero@iit.it
 * website: www.robotcub.org
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * A copy of the license can be found at
 * http://www.robotcub.org/icub/license/gpl.txt
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
 */

/* @file       eOcfg_nvsEP_sk_usrcbk_ebx.c
    @brief      This file keeps the user-defined functions used in every ems board ebx for endpoint mc
    @author     valentina.gaggero@iit.it
    @date       05/04/2012
 **/


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include "stdlib.h" 
#include "string.h"
#include "stdio.h"

#ifdef _ICUB_CALLBACK_
//#include "IRobotInterface.h"
#include "FeatureInterface.h"
#endif

#include "EoCommon.h"
#include "EOarray.h"
#include "EOnv_hid.h"

#include "EoSkin.h"
#include "eOcfg_nvsEP_sk.h"
#include "eOcfg_nvsEP_sk_hid.h"

#include "eOcfg_nvsEP_sk_overridden_pc104.h"
#include "eOcfg_nvsEP_sk_emsboard_usr_hid.h"

// --------------------------------------------------------------------------------------------------------------------
// - declaration of extern public interface
// --------------------------------------------------------------------------------------------------------------------



// --------------------------------------------------------------------------------------------------------------------
// - declaration of extern hidden interface 
// --------------------------------------------------------------------------------------------------------------------

//#include "eOcfg_nvsEP_mngmnt_usr_hid.h"

// --------------------------------------------------------------------------------------------------------------------
// - #define with internal scope
// --------------------------------------------------------------------------------------------------------------------
#define SKIN_BOARD_MAXNUM					7  //each skin endpoint is composed by 7 skin boards (mtb3)
#define SKIN_TRIANGLE4BOARD_MAXNUM			16 //each mtb3 manages 16 skin-triangle
#define SKIN_POINTS4TRIANGLE_MAXNUM  		12 //each triangle sends 12 point (value)
#define SKIN_RECCANFRAME4TRIANGLE_MAXNUM 	2 //each triangle sends 12 points in two can frame
#define MAX_ACQUISITION 					1024

// --------------------------------------------------------------------------------------------------------------------
// - typedef with internal scope
// --------------------------------------------------------------------------------------------------------------------
// empty-section


// --------------------------------------------------------------------------------------------------------------------
// - declaration of static functions
// --------------------------------------------------------------------------------------------------------------------
void s_eo_cfg_nvsEP_sk_hid_print_arrayof10canframe(EOarray_of_10canframes *sk_array);
void s_eo_cfg__nvsEP_sk_hid_Histogram_Print(void);
void s_eo_cfg_nvsEP_sk_hid_Histogram_Reset(void);
void s_eo_cfg__nvsEP_sk_hid_ParseCanFrame(EOarray_of_10canframes *sk_array);
void s_eo_cfg_nvsEP_sk_hid_Dump_Data( const EOnv* nv);

// --------------------------------------------------------------------------------------------------------------------
// - definition (and initialisation) of static variables
// --------------------------------------------------------------------------------------------------------------------
//static uint32_t s_skin_matrix_histogram[SKIN_BOARD_MAXNUM][SKIN_TRIANGLE4BOARD_MAXNUM][SKIN_POINTS4TRIANGLE_MAXNUM];
uint32_t s_skin_matrix_histogramRecCanFrame[SKIN_BOARD_MAXNUM][SKIN_TRIANGLE4BOARD_MAXNUM][SKIN_RECCANFRAME4TRIANGLE_MAXNUM];

uint32_t count;

// --------------------------------------------------------------------------------------------------------------------
// - definition (and initialisation) of extern variables
// --------------------------------------------------------------------------------------------------------------------
// empty-section



// --------------------------------------------------------------------------------------------------------------------
// - definition of extern public functions
// --------------------------------------------------------------------------------------------------------------------

void s_eo_cfg_nvsEP_sk_hid_Dump_Data( const EOnv* nv)
{
	static uint8_t dump[1024] = {0};
	static struct timeval tv[1024] = {0};
	static struct timeval zero = {0};
	static uint32_t t = 0;

	EOarray_of_10canframes sk_array;
	memcpy( &sk_array, nv->rem, sizeof(EOarray_of_10canframes));

	int i, cardId, valid, mtbId, triangle, msgtype;

	for(i=0; i<sk_array.head.size; i++)
	{
		eOutil_canframe_t *canframe;
		int  j, p = 0;

		canframe = (eOutil_canframe_t*) &sk_array.data[i*sizeof(eOutil_canframe_t)];
		valid = (((canframe->id & 0x0F00) >> 8) == 3) ? 1 : 0;

		if(valid)
		{
			cardId = (canframe->id & 0x00f0) >> 4;
			switch (cardId)
			{
			case 14:
				mtbId = 0;
				break;
			case 13:
				mtbId = 1;
				break;
			case 12:
				mtbId = 2;
				break;
			case 11:
				mtbId = 3;
				break;
			case 10:
				mtbId = 4;
				break;
			case 9:
				mtbId = 5;
				break;
			case 8:
				mtbId = 6;
				break;
			}
			triangle = (canframe->id & 0x000f);
			msgtype= ((canframe->data[0])& 0x80);
			//			printf("\n mtb %d triangle %d\n", mtbId, triangle);

			if(t < MAX_ACQUISITION)
			{
				if( (0x03E0 == canframe->id) && (0x40 == (canframe->data[0])) )
				{
					gettimeofday(&(tv[t]),NULL);
					dump[t] = canframe->data[1];
					t++;
				}
			}
			else if(t==MAX_ACQUISITION)
			{
				for (p=0; p<MAX_ACQUISITION; p++)
				{
					fprintf(stdout, "%d\t\t%d%06d\n", dump[p], tv[p].tv_sec, tv[p].tv_usec);
				}

				FILE * log = fopen("/tmp/iii/log.txt", "rw");
				if(NULL == log)
					printf(" Te piacerebbe!\n");
				else
				{
					fprintf(log, "valore  -  timestamp\n");
					for (p=0; p<MAX_ACQUISITION; p++)
					{
						fprintf(log, "%d\t\t%d%d\n", dump[p], tv[p].tv_sec, tv[p].tv_usec);
						//fprintf(stdout, " 0x%0x\t\t%d:%d\n", dump[p], tv[p].tv_sec, tv[p].tv_usec);
					}
					fclose(log);
					printf("Fine!!\n");
				}

				// DIE HERE!!!
				//while(1);
				t++;

			}
			//else
			//{
			//	printf("Array full!!\n");
			//}

		}
	}
}

//sk-update
//#ifdef OVERRIDE_eo_cfg_nvsEP_sk_hid_UPDT_sstatus__arrayof10canframe
extern void eo_cfg_nvsEP_sk_hid_UPDT_sstatus__arrayof10canframe(uint16_t n, const EOnv* nv, const eOabstime_t time, const uint32_t sign)
{
	//	printf("new callback\n");
	// s_eo_cfg_nvsEP_sk_hid_Dump_Data(nv);
	EOarray_of_10canframes *sk_array = (EOarray_of_10canframes *)nv->rem;

	//	s_eo_cfg__nvsEP_sk_hid_ParseCanFrame(sk_array);
	//	s_eo_cfg__nvsEP_sk_hid_Histogram_Print();
	//	s_eo_cfg_nvsEP_sk_hid_print_arrayof10canframe(sk_array);
	//	count++;

	//	popopopopopo = 666;

	//	if(count < 10000)
	//	{
	//		//count=0;
	//		s_eo_cfg__nvsEP_sk_hid_ParseCanFrame(sk_array);
	//
	//	}
	////	else if(count == 10000 )
	//	{
	//		count++; //stop to print
	//		s_eo_cfg__nvsEP_sk_hid_Histogram_Print();
	//	}

	//
	//	connection with iCubInterface stuff
	//

#ifdef _ICUB_CALLBACK_
	FEAT_ID id;
	id.type = Skin;
	strcpy(id.name, "right_arm");
//	weweweqwe;
	void *featList;
	printf("iCub Callback, looking for %s\n", id.name);
	getRobotFeatureList_C(&id);
	findAndFill(&id, (char *)sk_array);

#endif
}
//#endif
// --------------------------------------------------------------------------------------------------------------------
// - definition of extern hidden functions
// --------------------------------------------------------------------------------------------------------------------




// --------------------------------------------------------------------------------------------------------------------
// - definition of static functions
// --------------------------------------------------------------------------------------------------------------------
void s_eo_cfg_nvsEP_sk_hid_print_arrayof10canframe(EOarray_of_10canframes *sk_array)
{
	eOutil_canframe_t *canframe;
	int i, j;

	//	printf("--- ARRAY SIZE = %d  ---- \n", sk_array->head.size);
	//	for(i=0; i<sk_array->head.size; i++)
	//	{
	//		canframe = (eOutil_canframe_t*) &sk_array->data[i*sizeof(eOutil_canframe_t)];
	//		printf("SID = 0x%0x  ", canframe->id);
	//		printf("DATA: 0x");
	//		for(j=0; j<canframe->size;j++)
	//		{
	//			printf("%0x", canframe->data[j]);
	//		}
	//		printf("   tri = %0x,  %0x", (canframe->id & 0x000f), (((canframe->data[0])& 0x80) ? 0xC0 :0x40) );
	//		printf("\n\n");
	//
	//	}

}


void s_eo_cfg_nvsEP_sk_hid_Histogram_Reset(void)
{
	//	memset(s_skin_matrix_histogram, 0, sizeof(s_skin_matrix_histogram));
	memset(s_skin_matrix_histogramRecCanFrame, 0, sizeof(s_skin_matrix_histogramRecCanFrame));
}

void s_eo_cfg__nvsEP_sk_hid_ParseCanFrame(EOarray_of_10canframes *sk_array)
{
	eOutil_canframe_t *canframe;
	int i, j;

	uint8_t boardId = 0;
	uint8_t boardAddr = 0;
	uint8_t triangle = 0;
	uint8_t point = 0 ;
	uint8_t point_offset;
	uint8_t msgtype = 0;
	uint8_t row = 0;
	uint8_t offset;

	if(sk_array->head.size > 0)
	{
		count++;
		//		printf("COUNT = %d", count);
	}

	for(i=0; i<sk_array->head.size; i++)
	{
		canframe = (eOutil_canframe_t*) &sk_array->data[i*sizeof(eOutil_canframe_t)];

		boardAddr = (canframe->id & 0x00f0)>>4;
		boardId = boardAddr - 8;
		if(boardId>6) //gli indirizzi sono 8....14
		{
			continue;
		}
		triangle = (canframe->id & 0x000f);
		msgtype= ((canframe->data[0])& 0x80);

		if(msgtype)
		{ //0xC0
			row = 1;
			offset = 7;
		}
		else
		{ //0x40
			row = 0;
			offset = 0;
		}

		s_skin_matrix_histogramRecCanFrame[boardId][triangle][row]++;
		/*
		 * 		questo può essere usato per creare la matrice di valori
		for(i = 0; i<canframe->size; i++)
		{
			point = offset+i;
			s_skin_matrix_histogram[boardId][triangle][point] = canframe->data[i+1];
		}
		 */

	}


}


void s_eo_cfg__nvsEP_sk_hid_Histogram_Print(void)
{

	uint8_t i,j,k;

	for(i=0; i<SKIN_BOARD_MAXNUM; i++)
	{

		printf("board addr: %0x\n", i+8);
		for(j=0; j<SKIN_TRIANGLE4BOARD_MAXNUM; j++)
		{
			printf("    t:%0x - %0x, %0x | ", j, s_skin_matrix_histogramRecCanFrame[i][j][0], s_skin_matrix_histogramRecCanFrame[i][j][1]);
		}
		printf("\n");
	}
}

// --------------------------------------------------------------------------------------------------------------------
// - end-of-file (leave a blank line after)
// --------------------------------------------------------------------------------------------------------------------



