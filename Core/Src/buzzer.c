/*******************************************************************************
                      ��Ȩ���� (C), 2022-,NCUROBOT
 *******************************************************************************
  �� �� ��   : buzzer.c
  �� �� ��   :
  ��    ��   : ����
  ��������   :
  ����޸�   :
  ��������   :
  �����б�   :
*******************************************************************************/
/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "buzzer.h"
#include "tim.h"

/* �ڲ��궨�� ----------------------------------------------------------------*/

/* �ڲ��Զ����������͵ı��� --------------------------------------------------*/

/* �ڲ����� ------------------------------------------------------------------*/
const tNote lan_note[]=
{
  {L6,T/8},{M3,T/8},{M3,T/8},{M3,T/8},{M3,T/4},{M3,T/8},{M2,T/8},
  {M1,T/8},{M1,T/16},{M2,T/16},{M1,T/8},{L7,T/8},{L6,T/4},
  {M6,T/8},{M6,T/8},{M6,T/8},{M6,T/8},{M6,T/4},{M6,T/8},{M5,T/8},
    
  {M3,T/8},{M5,T/8},{M5,T/8},{M4,T/8},{M3,T/2},
  {M3,T/8},{M6,T/8},{M6,T/8},{M5,T/8},{M3,T/4},{M3,T/8},{M2,T/8},
  {M1,T/8},{M2,T/8},{M1,T/8},{L7,T/8},{L6,T/4},{L3,T/4},
  
  {L3,T/8},{M1,T/8},{M1,T/8},{L7,T/8},{L6,T/4},{L6,T/8},{M3,T/8},
  {M2,T/8},{M2,T/16},{M1,T/16},{L7,T/8},{L5,T/8},{L6,T/2},
  ///
  {L6,T/8},{M3,T/8},{M3,T/8},{M3,T/8},{M3,T/4},{M3,T/8},{M2,T/8},
  {M1,T/8},{M1,T/16},{M2,T/16},{M1,T/8},{L7,T/8},{L6,T/4},
  {M6,T/8},{M6,T/8},{M6,T/8},{M6,T/8},{M6,T/4},{M6,T/8},{M5,T/8},
    
  {M3,T/8},{M5,T/8},{M5,T/8},{M4,T/8},{M3,T/2},
  {M3,T/8},{M6,T/8},{M6,T/8},{M5,T/8},{M3,T/4},{M3,T/8},{M2,T/8},
  {M1,T/8},{M2,T/8},{M1,T/8},{L7,T/8},{L6,T/4},{L3,T/4},
  
  {L3,T/8},{M1,T/8},{M1,T/8},{L7,T/8},{L6,T/4},{L6,T/8},{M3,T/8},
  {M2,T/8},{M2,T/16},{M1,T/16},{L7,T/8},{L5,T/8},{L6,T/2},

  {0,0}//����
};


const tNote gala_note[] = {
    {note_5B, 1}, {note_G, 1}, {note_5B, 2}, {note_G, 1}, {note_5B, 2}, {note_G, 1}, {note_5D, 2}, {note_G, 1}, {note_5C, 1}, {note_5C, 1},
    {note_G, 1}, {note_5B, 1}, {note_5C, 1}, {note_5B, 1}, {note_G, 1}, {note_5B, 2}, {note_G, 1}, {note_5B, 2}, {note_G, 1}, {note_5D, 2},
    {note_G, 1}, {note_5C, 1}, {note_5C, 1}, {note_G, 1}, {note_5B, 1}, {note_5C, 1}, {note_5B, 1}, {note_G, 1}, {note_5B, 2}, {note_G, 1},
    {note_5B, 2}, {note_G, 1}, {note_5D, 2}, {note_G, 1}, {note_5C, 1}, {note_5C, 1}, {note_G, 1}, {note_5B, 1}, {note_5C, 1}, {note_5B, 1},
    {note_G, 1}, {note_5B, 2}, {note_G, 1}, {note_5B, 2}, {note_G, 1}, {note_5D, 2}, {note_G, 1}, {note_5C, 1}, {note_5C, 1}, {note_G, 1},
    {note_D, 2}, {note_E, 6}, {note_D, 2}, {note_E, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5C, 4}, {note_5B, 4}, {note_E, 4},
    {note_D, 2}, {note_E, 6}, {note_D, 2}, {note_E, 2}, {note_D, 2}, {note_E, 2}, {note_5C, 8}, {note_5B, 2}, {note_5D, 4}, {note_E, 10},
    {note_D, 2}, {note_E, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5C, 4}, {note_5B, 4}, {note_E, 4}, {note_D, 2}, {note_E, 6},
    {note_D, 2}, {note_E, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5C, 4}, {note_5D, 10}, {0, 4}, {note_E, 2}, {0, 0.2}, {note_E, 2},
    {note_D, 1}, {note_E, 3}, {note_D, 2}, {note_E, 2}, {note_G, 2}, {0, 2}, {note_E, 2}, {0, 0.2}, {note_E, 2}, {note_D, 1}, {note_E, 3},
    {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_C, 6}, {0, 2}, {note_E, 2}, {0, 0.2}, {note_E, 2}, {note_D, 1}, {note_E, 3}, {note_D, 2},
    {note_C, 2}, {note_D, 2}, {0, 2}, {note_E, 2}, {0, 0.2}, {note_E, 2}, {note_D, 1}, {note_E, 3}, {note_D, 2}, {note_E, 2}, {note_G, 2},
    {0, 2}, {note_E, 2}, {0, 0.2}, {note_E, 2}, {note_D, 1}, {note_E, 3}, {note_D, 2}, {note_E, 2}, {note_5C, 4}, {note_C, 6}, {0, 2},
    {note_E, 2}, {0, 0.2}, {note_E, 2}, {note_D, 1}, {note_E, 3}, {note_D, 2}, {note_B, 2}, {note_A, 1}, {note_3G, 5}, {0, 1}, {note_3G, 1},
    {0, 0.2}, {note_3G, 1}, {0, 0.2}, {note_3G, 1}, {note_G, 4}, {note_E, 3}, {note_D, 1}, {note_C, 2}, {0, 0.2}, {note_C, 4}, {0, 1}, {note_C, 2},
    {0, 0.05}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_A, 6}, {0, 2}, {note_A, 2}, {note_E, 2}, {note_D, 2}, {note_C, 2}, {note_D, 6},
    {0, 2}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6},
    {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1},
    {note_G, 4}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4},
    {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3},
    {note_5C, 4}, {note_5D, 6}, {note_E, 4}, {note_D, 2}, {0, 4}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1},
    {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 5}, {note_G, 1}, {note_5A, 2},
    {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5},
    {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5C, 4}, {note_5A, 5},
    {note_G, 1}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_5C, 4}, {note_5D, 6}, {note_D, 2}, {note_E, 2}, {note_D, 1}, {note_C, 12},
    {0, 4}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6},
    {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1},
    {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1},
    {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4}, {note_G, 1}, {note_5A, 3},
    {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2},
    {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 5},
    {note_G, 1}, {note_5A, 2}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4},
    {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2},
    {note_5C, 4}, {note_5A, 5}, {note_G, 1}, {note_5A, 2}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8},
    {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2},
    {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3},
    {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3},
    {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4}, {note_G, 1}, {note_5A, 3}, {note_G, 1},
    {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2},
    {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4}, {note_G, 1},
    {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4},
    {0, 0.5}, {note_G, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 5}, {note_G, 1}, {note_5A, 2}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1},
    {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6},
    {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1},
    {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4},
    {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3},
    {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5},
    {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 5},
    {note_G, 1}, {note_5A, 2}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4},
    {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2},
    {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2},
    {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6},
    {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 5}, {note_G, 1}, {note_5A, 2}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1},
    {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4},
    {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3},
    {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5},
    {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4},
    {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4},
    {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2},
    {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2},
    {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6},
    {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1},
    {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4},
    {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3},
    {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5},
    {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4},
    {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4},
    {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2},
    {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2},
    {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6},
    {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 5}, {note_G, 1}, {note_5A, 2}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1},
    {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4},
    {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3},
    {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5},
    {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4},
    {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4},
    {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2},
    {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2},
    {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6},
    {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 5}, {note_G, 1}, {note_5A, 2}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1},
    {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4},
    {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3},
    {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5},
    {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4},
    {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4},
    {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2},
    {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2},
    {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6},
    {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 5}, {note_G, 1}, {note_5A, 2}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1},
    {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4},
    {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3},
    {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5},
    {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4},
    {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4},
    {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2},
    {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2},
    {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6},
    {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1},
    {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4},
    {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3},
    {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5},
    {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4},
    {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4},
    {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2},
    {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2},
    {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6},
    {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1},
    {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4},
    {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3},
    {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5},
    {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 5},
    {note_G, 1}, {note_5A, 2}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4},
    {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2},
    {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2},
    {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6},
    {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1},
    {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4},
		{note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3},
		{note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5},
		{note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 5},
		{note_G, 1}, {note_5A, 2}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4},
		{note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2},
		{note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2},
		{0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6},
		{note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1},
		{note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4},
		{note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3},
		{note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5},
		{note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 5},
		{note_G, 1}, {note_5A, 2}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4},
		{note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2},
		{note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2},
		{0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6},
		{note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1},
		{note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4},
		{note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3},
		{note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5},
		{note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 5},
		{note_G, 1}, {note_5A, 2}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4},
		{note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2},
		{note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2},
		{0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6},
		{note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1},
		{note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4},
		{note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3},
		{note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5},
		{note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 5},
		{note_G, 1}, {note_5A, 2}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4},
		{note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4}, {note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2},
		{note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2},
		{0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5D, 4}, {note_5C, 6},
		{note_C, 2}, {note_D, 2}, {note_E, 2}, {note_G, 4}, {note_5A, 4}, {note_G, 1}, {note_5A, 3}, {note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1},
		{note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 6}, {note_E, 2}, {note_G, 2}, {note_E, 1}, {note_G, 3}, {note_5B, 4},
		{note_5C, 6}, {note_C, 2}, {note_D, 2}, {note_E, 2}, {note_5B, 4}, {note_5A, 6}, {0, 0.2}, {note_5A, 2}, {note_G, 1}, {note_5A, 3},
		{note_G, 1}, {0, 0.1}, {note_G, 3}, {0, 0.1}, {note_D, 2}, {0, 0.1}, {note_D, 8}, {note_E, 4}, {note_F, 4}, {note_G, 4}, {0, 0.5},

		{0,0}//end

};

/* �ڲ�����ԭ������ ----------------------------------------------------------*/
void Timer_Set(TIM_HandleTypeDef* htim, uint32_t channel, uint32_t frequency, float dutyCycle);

/* �������岿�� --------------------------------------------------------------*/
/**
  * @brief				��������LED����
  * @param[out]		��ͬƵ�ʼ���Ӧ����
  * @param[in]		note������long����
  * @retval				
*/
float db_value = 0.5;
void Note(int note,float Long)
{
	Timer_Set(&htim12, TIM_CHANNEL_2, note, db_value);

	HAL_Delay(Long*200);
}

// ����ռ�ձȺ�Ƶ�ʵĺ���
void Timer_Set(TIM_HandleTypeDef* htim, uint32_t channel, uint32_t frequency, float dutyCycle)
{
    // ȷ��Ƶ�ʺ�ռ�ձ��ں���Χ��
    if (frequency == 0 || dutyCycle < 0.0f || dutyCycle > 100.0f)
        return;

    // ���㶨ʱ����ʱ��Ƶ��
    uint32_t timerClock = 2400000; // Ĭ�϶�ʱ����ʱ��Ƶ��Ϊ 100MHz

    // �������ں�Ԥ��Ƶ��
    uint32_t prescaler = timerClock / frequency;
		
		__HAL_TIM_SET_AUTORELOAD(htim, prescaler);//����ARR

    // ����Ƚ�ֵ
    uint32_t compareValue = (uint32_t)((dutyCycle / 100.0f) * prescaler);

    // ����ͨ�����ñȽ�ֵ

    __HAL_TIM_SET_COMPARE(htim, channel, compareValue);
	  HAL_TIM_PWM_Start(htim,channel); 
}
/********** ���㡷-GALA**********/

void Gala_Music_Play(void)
{
	static uint8_t i=0;
	while(1)
	{
	  if(gala_note[i].mTime==0 && gala_note[i].mName==0)
		{
			Timer_Set(&htim12, TIM_CHANNEL_2, 1, 0);
			break;
		}
		Note(gala_note[i].mName,gala_note[i].mTime);
		i++;
	}

}

void Lan_Music_Play(void)
{
  static uint8_t i=0;
	while(1)
	{
	  if(lan_note[i].mTime==0 && lan_note[i].mName==0)
		{
			Timer_Set(&htim12, TIM_CHANNEL_2, 1, 0);
			break;
		}
		Note(lan_note[i].mName,lan_note[i].mTime / 200.f);
		i++;
		Note(0,10.f/200.f);
	}
}
