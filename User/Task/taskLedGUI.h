/*! @file
********************************************************************************
<PRE>
ģ����       : ����ģ��
�ļ���       : taskGUI.h
����ļ�     :
�ļ�ʵ�ֹ��� : �˻�����,LED����,����ɨ��
����         : <--->
�汾         : 1.0
--------------------------------------------------------------------------------
��ע         :
--------------------------------------------------------------------------------
�޸ļ�¼ :
�� ��        �汾   �޸���         �޸�����
2010/10/05   1.0    <xxxx>         ����
</PRE>
********************************************************************************

  * ��Ȩ����(c) YYYY, <xxx>, ��������Ȩ��

*******************************************************************************/
#ifdef _GUILED_

#ifndef _TASKLEDGUI_H
#define _TASKLEDGUI_H

/* Includes ------------------------------------------------------------------*/


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
#define	N34  0x00
#define	N33  0x01           //���߷�ʽ
#define	n81  0x00           //���ݸ�ʽ ��У�� ֹͣλ1
#define	e81  0x01           //żУ��
#define	o81  0x02           //��У��
#define	n82  0x03
#define Baud12  0x00        //������
#define Baud24  0x01
#define Baud48  0x02
#define Baud96  0x03
#define Baud192 0x04
#define rtu485  0x01
#define calib   0x02
#define CYCNO   0x00
#define CYCYES  0x01


enum EMLCD_DISP_DEFAULT
{
	DISP_UINT_U  = 0,
	DISP_UINT_I  = 1,
	DISP_UINT_P  = 2,
	DISP_UINT_PF = 3,
	DISP_UINT_EP = 4,
	DISP_UINT_THD = 5,
	DISP_UINT_DEM = 6,
};

enum EMLCD_DO_MODE
{
	DO_MODE_OFF = 0,
	DO_MODE_ALR = 1,
	DO_MODE_REM = 2,
};

enum EMLCD_AO_MODE
{
    AO_MODE_OFF = 0,
    AO_MODE_420 = 1,
	AO_MODE_020 = 2,
	AO_MODE_1220 = 3,
};

enum EMLCD_DO_ITEM
{
#if(FUNCTION_VOLTAGE == 1)
	DO_ITEM_Ua_H = 0,
	DO_ITEM_Ua_L = 1,
	DO_ITEM_Ub_H = 2,
	DO_ITEM_Ub_L = 3,
	DO_ITEM_Uc_H = 4,
	DO_ITEM_Uc_L = 5,
#endif
#if(FUNCTION_CURRENT == 1)
	DO_ITEM_Ia_H = 0,
	DO_ITEM_Ia_L = 1,
	DO_ITEM_Ib_H = 2,
	DO_ITEM_Ib_L = 3,
	DO_ITEM_Ic_H = 4,
	DO_ITEM_Ic_L = 5,
#endif
	DO_ITEM_F_H = 6,
	DO_ITEM_F_L = 7,

	DO_ITEM_DI1_H = 8,
	DO_ITEM_DI2_H = 9,
	DO_ITEM_DI3_H = 10,
	DO_ITEM_DI4_H = 11,
	DO_ITEM_DI1_L = 12,
	DO_ITEM_DI2_L = 13,
	DO_ITEM_DI3_L = 14,
	DO_ITEM_DI4_L = 15,
};

enum EMLCD_AO_ITEM
{
#if(FUNCTION_VOLTAGE == 1)
	AO_ITEM_UA =  0,
	AO_ITEM_UB =  1,
	AO_ITEM_UC =  2,
#endif
#if(FUNCTION_CURRENT == 1)
	AO_ITEM_IA =  0,
	AO_ITEM_IB =  1,
	AO_ITEM_IC =  2,
#endif	
	AO_ITEM_F   = 3,
};

#define BrightLevel_Off 0x00//���ȵȼ�
#define BrightLevel_1 0x01
#define BrightLevel_2 0x02
#define BrightLevel_3 0x03
#define BrightLevel_4 0x04
#define BrightLevel_5 0x05

#define SaveYes    0x01
#define SaveNO     0x02
#define ReadMode   0x01
#define ProgMode   0x02


#define MAX_NetMode        1	  // ���߷�ʽ���ֵ
#define MIN_NetMode        0      // ���߷�ʽ��Сֵ

#define MAX_PT          9999	  // PT������ֵ
#define MIN_PT		       1      // PT�����Сֵ

#define MAX_CT          9999	  // CT������ֵ
#define MIN_CT		       1      // CT�����Сֵ

#define MAX_Addr         247	  // ���Ա��ַ���ֵ
#define MIN_Addr		   0      // ���Ա��ַ��Сֵ

#define MAX_Baud           4	  // ���������ֵ
#define MIN_Baud		   0      // ��������Сֵ

#define MAX_DataFormat     3	  // ���ݸ�ʽ���ֵ
#define MIN_DataFormat	   0      // ���ݸ�ʽ��Сֵ

#define MAX_DataProt       2	  // ���ݸ�ʽ���ֵ
#define MIN_DataProt	   1      // ���ݸ�ʽ��Сֵ

#define MAX_Cycle          2	  // ��ʾ�л�ʱ�����ֵ
#define MIN_Cycle		   1      // ��ʾ�л�ʱ����Сֵ

#define MAX_Code        9999	  // �������ֵ
#define MIN_Code 		   1	  // ������Сֵ

#define MAX_BlackTime    255	  // ���ȵȼ����ֵ
#define MIN_BlackTime	   1      // ���ȵȼ���Сֵ

#define MAX_Alarm        200	  // ��˸�������ֵ
#define MIN_Alarm		   0      // ��˸������Сֵ

#define MAX_Disp           8	  // Ĭ����ʾ���ֵ
#define MIN_Disp	       0      // Ĭ����ʾ��Сֵ

#define MAX_Ver         9999	  // ����汾���ֵ
#define MIN_Ver	           0      // ����汾��Сֵ

#define MAX_DO_Mode       2
#define MIN_DO_Mode       0

#define MAX_DO_Time    9999
#define MIN_DO_Time       0

#define MAX_DO_Item      80
#define MIN_DO_Item       0

#define MAX_DO_Ual     9999
#define MIN_DO_Ual        0

#define MAX_DO_Hys     9999
#define MIN_DO_Hys        0

#define MAX_DO_Dely    9999
#define MIN_DO_Dely       0

#define MAX_AO_Mode       3
#define MIN_AO_Mode       0

#define MAX_AO_Item      26
#define MIN_AO_Item       0

#define MAX_AO_DS      9999
#define MIN_AO_DS         0

#define MAX_AO_FS      9999
#define MIN_AO_FS         0

/* Exported functions ------------------------------------------------------- */

extern BOOL g_AoOutEnable;
extern BOOL g_fftEnable;
extern u8 DispMode;
extern u8 LEDLEVEL;
extern volatile u8 vg_Display_Value[16]; // ��ʾ���滺��

void Task_GUI_init(void);
void Task_Timer_init(void);
void GUI_Timer_On(void);
void DispChar(u8 num,u8 ch1, u8 ch2, u8 ch3, u8 ch4);
void DispBitChar(u8 Index, u8 ch);

void Task_GUI_Function(void);
void Task_Timer_Function(void);
void GUI_SetComFlag(void);
void GUI_SetDispCtrl(u8 Group, u8 State, u32 DlyNum);
void DispValue(u8 num,s32 DispNum, u8 Decimal, u8 DispWidth, BOOL bFlash, u8 FlashDec, BOOL bEnableDisp, BOOL bSet);
s32 JudgeSetNewValue(BOOL *pUpdataFlag, s32 OldValue, s32 *pNewValue, s32 MinValue, s32 MaxValue);
void GetSetNewValue(void);
void Disp_IO_Status(u8 InStatus,u8 OutStatus);

#endif /* _TASKGUI_H */

#endif // #ifdef _GUILED_

//===========================================================================
// No more.
//===========================================================================


