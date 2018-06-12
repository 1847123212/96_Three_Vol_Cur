/*! @file
********************************************************************************
<PRE>
ģ����       : Ӳ������ģ��
�ļ���       : drvI2C.h
����ļ�     :
�ļ�ʵ�ֹ��� : I2C��������
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


#ifndef _RN8302B_H
#define _RN8302B_H

/* Includes ------------------------------------------------------------------*/
#include "Macro.h"
/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
#define STDUn                                   220
#define STDIb                                   5
#define CalVoltate                              44000000         //220V��ѹ��У��
#define CalCurrent                              50000000         //5A ������У��
#define STDP                                    262260437        //��׼���й�����
#define STDP_05L                                131130218        //��׼���й�����
#define RN8302_fosc                             8000000        //����Ƶ�� ��׼ 8192000
#define RO                                      0x00
#define RW                                      0x01
#define bank0                                   0x00
#define bank1                                   0x01
#define bank2                                   0x02
#define bank3                                   0x03
#define bank4                                   0x04
#define WRENABLE                                0xE5
#define WRDISABLE                               0xDC
#define SAMPTEMPCLR                             0x10                //50Hz����������������
#define CLREMMIFH                               0xFF                //����������жϱ�־
#define CLREMMIFL                               0xFF
#define SAMPSTART                               0x20
#define SOFTRST                                 0xFA
#define EMMOD                                   0xA2                //EMMģʽ
#define SLPMOD                                  0x18
#define NVM1MOD                                 0xE1
#define NVM2MOD                                 0x5C
#define CHANNELEN                               0xFF
#define ADCGAINVAL                              0x00                //ADC ͨ�������趨����ѹͨ��1�����档
//#define HF6400                            0x031F                        //6400����
#define EGYRDMODVAL                             0x40                //���ڵ��ܶ�ȡ�����㡣
#define LNWIREMODE                              0x00        //�������߽���ģʽ��
#define LLWIREMODE                              0x33        //�������߽���ģʽ��
#define GAIN_1                                  0x00
#define GAIN_2                                  0x01
#define GAIN_4                                  0x10
#define GAIN_8                                  0x11
#define CALIB_UIE                               0xb0
#define CALIB_ANGLE                             0xe8       
#define CALIB_IOFFSET                           0x1f       
#define CALIB_SECTION_I                         0xa0        
#define CALIB_AnoPwm                            0xc0        
#define CALIB_SetPwm							0xc1
#define CALIB_SET_DEFAULT                       0xf9
#define CALIB_SET_ZERO                          0x04
#define CALIB_WRITEDATA                         0x05
//#define HFCONST1                                      0x39
//#define HFCONST0                                      0x07                        //���Գ���
//#define HFCONST1                                      0xCE


// һ�β��������
__packed typedef struct
{
    // ��λ:0.01V
    float U;          // ��ѹ
    // ��λ:0.01V
    float LineU;      // �ߵ�ѹ
    // ��λ:0.0001A
    float I;          // ����
    // ��λ:0.0001A
    float P;          // �й�����
    // ��λ:0.00001kvar
    float Q;          // �޹�����
    // ��λ:0.00001kVA
    float S;          // ���ڹ���
    // ��λ:0.001
    float PF;         // ��������
    // ��λ:0.1
}POWER_Real2_ValStruct;


__packed typedef struct
{
    POWER_Real2_ValStruct Real2_Val[PH_TH];

    float Pt;
    float Qt;
    float St;
    float PFTA;
    float Uavr;
    float ULavr;
    float Iavr;
    float Freq;
}POWER2_ValStruct;

// ���β��������
__packed typedef struct
{
    // ��λ:0.01V
    int U;              // ���ѹ
    // ��λ:0.01V
    int LineU;          // �ߵ�ѹ
    // ��λ:0.0001A
    int I;              // �����
    // ��λ:0.00001kW=0.1w
    int P;              // �й�����
    // ��λ:0.00001kvar
    int Q;              // �޹�����
    // ��λ:0.00001kVA
    int S;              // ���ڹ���
    // ��λ:0.001
    int PF;             // ��������
}POWER_Real22_ValStruct;


__packed typedef struct
{
    POWER_Real22_ValStruct Real22_Val[PH_TH];

    int Pt;
    int Qt;
    int St;
    int PFTA;
    int Uavr;
    int ULavr;
    int Iavr;
    int Io;
    int Pavr;
    int Qavr;
    int Savr;
    int Freq;
}POWER22_ValStruct;

// ������������(��ȡ������)
__packed typedef struct
{
    //��λ:0.01V
    u16 U;          //���β��ѹ AC
    //��λ:0.0001A
    u32 I;          //���β���� B
    //��λ:0.00001kW=0.1w
    s32 P;          //���β��й����� A/B/C/��
    //��λ:0.00001kvar
    s32 Q;          //���β��޹����� A/B/C/��
    //��λ:0.00001kVA
    u32 S;          //���β����ڹ���
    //��λ:0.001
    u16 PF;         //��������ֵ
}POWER_Read_ValStruct;


// У��ɶ�
__packed typedef struct
{
    POWER_Read_ValStruct Real_Read_Val[PH_TH];

}POWER2_Read_ValStruct;


typedef struct
{
    unsigned char addr;
    unsigned char bytenum;
    unsigned char rw;
    unsigned int  data;
} RegStructure;

// RN8209 �Ĵ���
typedef struct
{
    RegStructure        SYSCON;
    RegStructure        EMUCON;
    RegStructure        HFConst;
    RegStructure        PStart;
    RegStructure        DStart;
    RegStructure        GPQA;
    RegStructure        GPQB;
    RegStructure        PhsA;
    RegStructure        PhsB;
    RegStructure        QPhsCal;
    RegStructure        APOSA;
    RegStructure        APOSB;
    RegStructure        RPOSA;
    RegStructure        RPOSB;
    RegStructure        IARMSOS;
    RegStructure        IBRMSOS;
    RegStructure        IBGain;
    RegStructure        D2FPL;
    RegStructure        D2FPH;
    RegStructure        DCIAH;
    RegStructure        DCIBH;
    RegStructure        DCUH;
    RegStructure        DCL;
    RegStructure        EMUCON2;
    RegStructure        PFCnt;
    RegStructure        DFcnt;
    RegStructure        IARMS;
    RegStructure        IBRMS;
    RegStructure        URMS;
    RegStructure        UFreq;
    RegStructure        PowerPA;
    RegStructure        PowerPB;
    RegStructure        PowerQ;
    RegStructure        EnergyP;
    RegStructure        EnergyP2;
    RegStructure        EnergyD;
    RegStructure        EnergyD2;
    RegStructure        EMUStatus;
    RegStructure        SPL_IA;
    RegStructure        SPL_IB;
    RegStructure        SPL_U;
    RegStructure        UFreq2;
    RegStructure        IE;
    RegStructure        IF;
    RegStructure        RIF;
    RegStructure        SysStatus;
    RegStructure        RData;
    RegStructure        WData;
    RegStructure        DeviceID;
    RegStructure        WREN;
    RegStructure        WPRO;
    RegStructure        IAChoice;
    RegStructure        IBChoice;
    RegStructure        SOFT_RST;
} All_REG_Data;

struct RN_Coefficient
{
    unsigned short HFConst1;
    unsigned short HFConst2;
    unsigned short IStart_PS;
    unsigned short IStart_Q;
    unsigned short LostVoltT;
    unsigned short ZXOT;
    short GSUA;
    short GSUB;
    short GSUC;
    short GSIA;
    short GSIB;
    short GSIC;
    unsigned int PHSIA;
    unsigned int PHSIB;
    unsigned int PHSIC;
    unsigned int PA_PHSL;
    unsigned int PB_PHSL;
    unsigned int PC_PHSL;
};


/* Exported functions ------------------------------------------------------- */
extern POWER2_ValStruct vg_Power_Val;
extern POWER22_ValStruct vg_Power2_Val;
extern POWER2_Read_ValStruct vg_Read_Val;
extern u32 CheckSum;
extern void bsp_InitRN8023(void);
extern void RN8032_Adjust(u8 Cmd, u8 Phase, u8 *pAdjustData);
void Task_Power_Function(void);
extern void RN8032_Updata(void);
extern void InitRNParam(void);

//#define PI 3.1415926
#endif /* _DRVI2C_H */

//===========================================================================
// No more.
//===========================================================================


