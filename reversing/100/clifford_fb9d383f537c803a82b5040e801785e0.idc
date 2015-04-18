//
// +-------------------------------------------------------------------------+
// |   This file has been generated by The Interactive Disassembler (IDA)    |
// |           Copyright (c) 2013 Hex-Rays, <support@hex-rays.com>           |
// |                      License info: 48-325F-7034-FF                      |
// |                     Rico Baumgart, personal license                     |
// +-------------------------------------------------------------------------+
//
//
//      This file should be used in the following way:
//         - reload executable into IDA with using switch -c
//         - use File, Load IDC file and load this file.
//
//      NOTE: This file doesn't contain all information from the database.
//

#define UNLOADED_FILE   1
#include <idc.idc>

static main(void)
{
  // set 'loading idc file' mode
  SetCharPrm(INF_GENFLAGS, INFFL_LOADIDC|GetCharPrm(INF_GENFLAGS));
  GenInfo();            // various settings
  Segments();           // segmentation
  Enums();              // enumerations
  Structures();         // structure types
  Patches();            // manual patches
  SegRegs();            // segment register values
  Bytes();              // individual bytes (code,data)
  Functions();          // function definitions
  // clear 'loading idc file' mode
  SetCharPrm(INF_GENFLAGS, ~INFFL_LOADIDC&GetCharPrm(INF_GENFLAGS));
}

//------------------------------------------------------------------------
// General information

static GenInfo(void) {

        DeleteAll();    // purge database
	SetPrcsr("metapc");
	SetCharPrm(INF_COMPILER, 6);
	StringStp(0xA);
	Tabs(1);
	Comments(0);
	Voids(0);
	XrefShow(0);
	AutoShow(1);
	Indent(0);
	CmtIndent(24);
	TailDepth(0x10);
	LoadTil("gnuunx");
}

//------------------------------------------------------------------------
// Information about segmentation

static Segments(void) {
	SetSelector(0X1,0);
	SetSelector(0X2,0);
	SetSelector(0X3,0);
	SetSelector(0X4,0);
	SetSelector(0X5,0);
	SetSelector(0X6,0);
	SetSelector(0X7,0);
	SetSelector(0X8,0);
	SetSelector(0X9,0);
	SetSelector(0XA,0);
	SetSelector(0XB,0);
	SetSelector(0XC,0);
	SetSelector(0XD,0);
	SetSelector(0XE,0);
	SetSelector(0XF,0);
	;
	SegCreate(0X4004D0,0X4004E8,0X1,2,5,2);
	SegRename(0X4004D0,".init");
	SegClass (0X4004D0,"CODE");
	SegDefReg(0x4004D0,"ds",0xD);
	SetSegmentType(0X4004D0,2);
	SegCreate(0X4004F0,0X400560,0X2,2,3,2);
	SegRename(0X4004F0,".plt");
	SegClass (0X4004F0,"CODE");
	SegDefReg(0x4004F0,"ds",0xD);
	SetSegmentType(0X4004F0,2);
	SegCreate(0X400560,0X4011C8,0X3,2,3,2);
	SegRename(0X400560,".text");
	SegClass (0X400560,"CODE");
	SegDefReg(0x400560,"ds",0xD);
	SetSegmentType(0X400560,2);
	SegCreate(0X4011C8,0X4011D6,0X4,2,5,2);
	SegRename(0X4011C8,".fini");
	SegClass (0X4011C8,"CODE");
	SegDefReg(0x4011C8,"ds",0xD);
	SetSegmentType(0X4011C8,2);
	SegCreate(0X4011D8,0X401264,0X5,2,10,2);
	SegRename(0X4011D8,".rodata");
	SegClass (0X4011D8,"CONST");
	SegDefReg(0x4011D8,"ds",0xD);
	SetSegmentType(0X4011D8,3);
	SegCreate(0X401264,0X4012B0,0X6,2,5,2);
	SegRename(0X401264,".eh_frame_hdr");
	SegClass (0X401264,"CONST");
	SegDefReg(0x401264,"ds",0xD);
	SetSegmentType(0X401264,3);
	SegCreate(0X4012B0,0X4013E4,0X7,2,10,2);
	SegRename(0X4012B0,".eh_frame");
	SegClass (0X4012B0,"CONST");
	SegDefReg(0x4012B0,"ds",0xD);
	SetSegmentType(0X4012B0,3);
	SegCreate(0X601E28,0X601E38,0X8,2,10,2);
	SegRename(0X601E28,".ctors");
	SegClass (0X601E28,"DATA");
	SegDefReg(0x601E28,"ds",0xD);
	SetSegmentType(0X601E28,3);
	SegCreate(0X601E38,0X601E48,0X9,2,10,2);
	SegRename(0X601E38,".dtors");
	SegClass (0X601E38,"DATA");
	SegDefReg(0x601E38,"ds",0xD);
	SetSegmentType(0X601E38,3);
	SegCreate(0X601E48,0X601E50,0XA,2,10,2);
	SegRename(0X601E48,".jcr");
	SegClass (0X601E48,"DATA");
	SegDefReg(0x601E48,"ds",0xD);
	SetSegmentType(0X601E48,3);
	SegCreate(0X601FE0,0X601FE8,0XB,2,10,2);
	SegRename(0X601FE0,".got");
	SegClass (0X601FE0,"DATA");
	SegDefReg(0x601FE0,"ds",0xD);
	SetSegmentType(0X601FE0,3);
	SegCreate(0X601FE8,0X602030,0XC,2,10,2);
	SegRename(0X601FE8,".got.plt");
	SegClass (0X601FE8,"DATA");
	SegDefReg(0x601FE8,"ds",0xD);
	SetSegmentType(0X601FE8,3);
	SegCreate(0X602030,0X602040,0XD,2,10,2);
	SegRename(0X602030,".data");
	SegClass (0X602030,"DATA");
	SegDefReg(0x602030,"ds",0xD);
	SetSegmentType(0X602030,3);
	SegCreate(0X602040,0X602068,0XE,2,3,2);
	SegRename(0X602040,".bss");
	SegClass (0X602040,"BSS");
	SegDefReg(0x602040,"ds",0xD);
	SetSegmentType(0X602040,9);
	SegCreate(0X602068,0X602084,0XF,2,3,2);
	SegRename(0X602068,"extern");
	SegClass (0X602068,"");
	SetSegmentType(0X602068,1);
	LowVoids(0x4004D0);
	HighVoids(0x602088);
}

//------------------------------------------------------------------------
// Information about enum types

static Enums(void) {
        auto id;
        BeginTypeUpdating(UTP_ENUM);
}

//------------------------------------------------------------------------
// Information about structure types

static Structures(void) {
        auto id;
        BeginTypeUpdating(UTP_STRUCT);
}

//------------------------------------------------------------------------
// Information about bytes

static Bytes_0(void) {
        auto x;
#define id x

	ExtLinA		(0X4004D0,	0,	"; File Name   : C:\\Users\\user\\Documents\\Visual Studio 2013\\Projects\\pCTF2015\\reversing\\100\\clifford_fb9d383f537c803a82b5040e801785e0.elf");
	ExtLinA		(0X4004D0,	1,	"; Format      : ELF64 for x86-64 (Executable)");
	ExtLinA		(0X4004D0,	2,	"; Imagebase   : 400000");
	ExtLinA		(0X4004D0,	3,	"; Interpreter '/lib64/ld-linux-x86-64.so.2'");
	ExtLinA		(0X4004D0,	4,	"; Needed Library 'libc.so.6'");
	ExtLinA		(0X4004D0,	5,	"; ");
	MakeCode	(x=0X4004D0);
	OpHex		(x,	1);
	MakeName	(0X4004D0,	".init_proc");
	MakeCode	(x=0X4004E3);
	OpHex		(x,	1);
	MakeQword	(0X4004F0);
	MakeArray	(0X4004F0,	0X2);
	MakeCode	(0X400500);
	MakeName	(0X400500,	".puts");
	MakeWord	(0X400506);
	MakeQword	(0X400508);
	MakeCode	(0X400510);
	MakeName	(0X400510,	".printf");
	MakeWord	(0X400516);
	MakeQword	(0X400518);
	MakeCode	(0X400520);
	MakeName	(0X400520,	".__libc_start_main");
	MakeWord	(0X400526);
	MakeQword	(0X400528);
	MakeCode	(0X400530);
	MakeName	(0X400530,	".calloc");
	MakeWord	(0X400536);
	MakeQword	(0X400538);
	MakeCode	(0X400540);
	MakeName	(0X400540,	".__isoc99_scanf");
	MakeWord	(0X400546);
	MakeQword	(0X400548);
	MakeCode	(0X400550);
	MakeName	(0X400550,	".exit");
	MakeWord	(0X400556);
	MakeQword	(0X400558);
	MakeCode	(0X400560);
	MakeName	(0X400560,	"start");
	MakeCode	(x=0X400569);
	OpHex		(x,	1);
	MakeCode	(x=0X40056F);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X400576);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X40057D);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeArray	(0X40058A,	0X2);
	MakeCode	(x=0X40058C);
	OpHex		(x,	1);
	MakeName	(0X40058C,	"gmon_start");
	MakeCode	(x=0X40059E);
	OpHex		(x,	1);
	MakeArray	(0X4005A3,	0XD);
	MakeCode	(0X4005B0);
	MakeCode	(x=0X4005B5);
	OpHex		(x,	1);
	MakeCode	(x=0X4005C2);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X4005CE);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X4005D5);
	OpHex		(x,	1);
	MakeCode	(x=0X4005F3);
	OpOff		(x,	0,	0);
	OpOff		(x,	128,	0);
	MakeCode	(x=0X40060D);
	OpHex		(x,	1);
	MakeArray	(0X400614,	0XC);
	MakeCode	(0X400620);
	MakeCode	(x=0X400639);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(0X400640);
	MakeArray	(0X400642,	0X2);
	MakeCode	(0X400644);
	MakeCode	(0X40067D);
	MakeCode	(x=0X400682);
	OpHex		(x,	1);
	MakeCode	(x=0X400688);
	OpHex		(x,	1);
	MakeCode	(x=0X400695);
	OpHex		(x,	1);
	MakeCode	(x=0X400698);
	OpHex		(x,	1);
	MakeCode	(x=0X4006B5);
	OpHex		(x,	1);
	MakeCode	(x=0X4006BB);
	OpHex		(x,	1);
	MakeCode	(x=0X4006C8);
	OpHex		(x,	1);
	MakeCode	(x=0X4006CD);
	OpHex		(x,	1);
	MakeCode	(x=0X4006D0);
	OpHex		(x,	1);
	MakeCode	(0X400706);
	MakeName	(0X400706,	"decode_potential_flag");
	MakeCode	(x=0X40070A);
	OpStkvar	(x,	0);
	MakeCode	(x=0X40070D);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400711);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400715);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40071B);
	OpStkvar	(x,	0);
	MakeCode	(x=0X40071E);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400725);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400728);
	OpStkvar	(x,	0);
	MakeCode	(x=0X40072F);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400732);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400736);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400739);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400742);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400747);
	OpHex		(x,	1);
	MakeCode	(x=0X40074A);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40074D);
	OpHex		(x,	1);
	MakeCode	(x=0X400754);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400757);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40075A);
	OpHex		(x,	1);
	MakeCode	(x=0X40075F);
	OpHex		(x,	1);
	MakeCode	(x=0X400762);
	OpHex		(x,	1);
	MakeCode	(x=0X400766);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40076C);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400771);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400774);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400777);
	OpStkvar	(x,	0);
	MakeCode	(x=0X40077A);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40077F);
	OpHex		(x,	1);
	MakeCode	(x=0X400782);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400785);
	OpHex		(x,	1);
	MakeCode	(x=0X40078C);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40078F);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400792);
	OpHex		(x,	1);
	MakeCode	(x=0X400795);
	OpHex		(x,	1);
	MakeCode	(x=0X400799);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40079F);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4007A4);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4007A7);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4007AB);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4007AE);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4007B3);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4007B7);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4007BC);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4007C4);
	OpStkvar	(x,	1);
	MakeCode	(0X4007CB);
	MakeName	(0X4007CB,	"verify");
	MakeCode	(x=0X4007D0);
	OpHex		(x,	1);
	MakeCode	(x=0X4007D7);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4007DE);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4007E4);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4007EC);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4007FA);
	OpStkvar	(x,	1);
	MakeComm	(0X40080F,	"size");
	MakeComm	(0X400814,	"nmemb");
	MakeCode	(x=0X40081C);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400820);
	OpStkvar	(x,	0);
	MakeCode	(x=0X40082C);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400838);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40083D);
	OpHex		(x,	1);
	MakeCode	(x=0X400841);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40084B);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400851);
	OpHex		(x,	1);
	MakeCode	(x=0X40085A);
	OpStkvar	(x,	0);
	MakeCode	(x=0X40085D);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400865);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400873);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400886);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400895);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4008A5);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4008AB);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4008B4);
	OpHex		(x,	1);
	MakeCode	(x=0X4008B8);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4008C3);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4008C7);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4008CA);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4008D2);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4008DB);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4008DF);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4008EA);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4008F3);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4008FA);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400903);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400908);
	OpHex		(x,	1);
	MakeCode	(x=0X40090C);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400912);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400915);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40091A);
	OpHex		(x,	1);
	MakeCode	(x=0X40091E);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400933);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400937);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40093F);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40094D);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400960);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400965);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40096D);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40097B);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40098E);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40099D);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4009A4);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4009AD);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4009B7);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4009BD);
	OpHex		(x,	1);
	MakeCode	(x=0X4009C6);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4009C9);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4009CD);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4009D0);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4009D8);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4009E1);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4009E8);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4009F1);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4009F6);
	OpHex		(x,	1);
	MakeCode	(x=0X4009FA);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400A04);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400A0A);
	OpHex		(x,	1);
	MakeCode	(x=0X400A13);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400A16);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400A1A);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400A1D);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400A25);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400A2A);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400A2D);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400A3C);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400A40);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400A4B);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400A50);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400A59);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400A60);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400A69);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400A6E);
	OpHex		(x,	1);
	MakeCode	(x=0X400A72);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400A7C);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400A82);
	OpHex		(x,	1);
	MakeCode	(x=0X400A8B);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400A8E);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400A92);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400A95);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400A9D);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400AA2);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400AA5);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400AB4);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400AB8);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400ABB);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400AC3);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400AC9);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400AD1);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400AD8);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400ADE);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400AEA);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400AED);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400AF8);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400AFE);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400B0B);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400B0E);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400B17);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400B1A);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400B21);
	OpHex		(x,	1);
	MakeCode	(x=0X400B25);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400B2F);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400B35);
	OpHex		(x,	1);
	MakeCode	(x=0X400B3E);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400B41);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400B45);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400B48);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400B4D);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400B50);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400B5F);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400B63);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400B6E);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400B77);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400B80);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400B87);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400B90);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400B93);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400B9A);
	OpHex		(x,	1);
	MakeCode	(x=0X400B9E);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400BA8);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400BAE);
	OpHex		(x,	1);
	MakeCode	(x=0X400BB7);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400BBA);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400BBE);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400BC9);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400BCC);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400BD1);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400BD4);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400BE3);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400BE7);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400BEA);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400BF2);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400BFB);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400C02);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400C0B);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400C10);
	OpHex		(x,	1);
	MakeCode	(x=0X400C14);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400C1E);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400C21);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400C29);
	OpHex		(x,	1);
	MakeCode	(x=0X400C32);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400C35);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400C39);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400C44);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400C47);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400C4C);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400C4F);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400C5B);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400C5F);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400C62);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400C6A);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400C76);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400C94);
	OpStkvar	(x,	1);
	MakeCode	(0X400CAC);
	MakeCode	(x=0X400CB1);
	OpHex		(x,	1);
	MakeCode	(0X400CBB);
	MakeCode	(x=0X400CC0);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400CC4);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400CC7);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400CD3);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400CDA);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400CE3);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400CE8);
	OpHex		(x,	1);
	MakeCode	(x=0X400CEC);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400CF3);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400CF9);
	OpHex		(x,	1);
	MakeCode	(x=0X400D02);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400D05);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400D08);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400D0C);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400D10);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400D13);
	OpStkvar	(x,	0);
	OpHex		(x,	1);
	MakeCode	(x=0X400D1A);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400D25);
	OpHex		(x,	1);
	MakeCode	(x=0X400D2B);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X400D32);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400D37);
	OpHex		(x,	1);
	MakeCode	(x=0X400D3A);
	OpHex		(x,	1);
	MakeCode	(x=0X400D3F);
	OpHex		(x,	1);
	MakeCode	(x=0X400D44);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400D53);
	OpOff		(x,	0,	0);
	OpOff		(x,	128,	0);
	MakeCode	(x=0X400D5A);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400D5E);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400D62);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400D65);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400D6A);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400D73);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400D77);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400D7F);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400D8E);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400DAB);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400DBA);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400DD7);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400DE6);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400E03);
	OpStkvar	(x,	1);
	MakeCode	(0X400E23);
	MakeCode	(x=0X400E28);
	OpHex		(x,	1);
	MakeCode	(x=0X400E2C);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X400E36);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X400E3B);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400E4F);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400E57);
	OpStkvar	(x,	1);
	MakeComm	(0X400E5F,	"jump here if order is not a number");
	MakeCode	(x=0X400E5F);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeComm	(0X400E69,	"status");
	MakeCode	(x=0X400E73);
	OpStkvar	(x,	1);
	MakeComm	(0X400E7D,	"size");
	MakeComm	(0X400E82,	"nmemb");
	MakeCode	(x=0X400E8A);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400E8E);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400E97);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400E9C);
	OpHex		(x,	1);
	MakeCode	(x=0X400EA3);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400EA7);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400EAA);
	OpStkvar	(x,	1);
	MakeComm	(0X400EAF,	"size");
	MakeComm	(0X400EB4,	"nmemb");
	MakeCode	(x=0X400EBF);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400EC3);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400ECB);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400ED0);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400ED3);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400EE0);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400EF0);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400EF3);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X400EFD);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400F06);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400F0F);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400F14);
	OpHex		(x,	1);
	MakeCode	(x=0X400F18);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400F1F);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400F25);
	OpHex		(x,	1);
	MakeCode	(x=0X400F2C);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X400F41);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400F45);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400F48);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400F4B);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400F50);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400F54);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400F57);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400F5C);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400F5F);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400F64);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400F6C);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400F6F);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400F7C);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400F7F);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400F82);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400F8E);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400F91);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400F9A);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400F9F);
	OpHex		(x,	1);
	MakeCode	(x=0X400FA3);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400FAA);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400FAD);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400FB5);
	OpHex		(x,	1);
	MakeCode	(x=0X400FBC);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X400FD1);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400FD5);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400FD8);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400FDD);
	OpStkvar	(x,	0);
	MakeCode	(x=0X400FE1);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400FE9);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400FF2);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X400FFC);
	OpStkvar	(x,	1);
	MakeCode	(x=0X400FFF);
	OpStkvar	(x,	1);
	MakeComm	(0X401003,	"order number");
	MakeComm	(0X401005,	"pointer to number input");
	MakeCode	(x=0X401011);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeComm	(0X40101B,	"status");
	MakeCode	(x=0X401025);
	OpStkvar	(x,	0);
	MakeCode	(x=0X40102C);
	OpStkvar	(x,	0);
	MakeCode	(x=0X401033);
	OpStkvar	(x,	0);
	MakeCode	(x=0X40103A);
	OpStkvar	(x,	0);
	MakeCode	(x=0X401041);
	OpStkvar	(x,	0);
	MakeCode	(x=0X401048);
	OpStkvar	(x,	0);
	MakeCode	(x=0X40104F);
	OpStkvar	(x,	0);
	MakeCode	(x=0X401056);
	OpStkvar	(x,	0);
	MakeCode	(x=0X40105D);
	OpStkvar	(x,	0);
	MakeCode	(x=0X401064);
	OpStkvar	(x,	0);
	MakeCode	(x=0X40106B);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X401075);
	OpStkvar	(x,	1);
	MakeCode	(x=0X401078);
	OpStkvar	(x,	1);
	MakeCode	(x=0X401086);
	OpStkvar	(x,	0);
	MakeCode	(x=0X40108F);
	OpStkvar	(x,	1);
	MakeCode	(x=0X40109C);
	OpStkvar	(x,	1);
	MakeCode	(x=0X4010A3);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X4010B5);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4010B9);
	OpStkvar	(x,	0);
	MakeCode	(x=0X4010BF);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X4010C4);
	OpStkvar	(x,	1);
	MakeComm	(0X4010CB,	"format");
	MakeComm	(0X4010D8,	"status");
	MakeArray	(0X4010E2,	0XE);
	MakeStr		(0X4010F0,	0X401101);
	MakeName	(0X4010F0,	"aHilLidRhn");
	MakeCode	(0X401101);
	MakeCode	(x=0X40111C);
	OpHex		(x,	1);
	MakeCode	(x=0X401129);
	OpHex		(x,	1);
	MakeCode	(x=0X401174);
	OpHex		(x,	1);
	MakeArray	(0X401179,	0X7);
	MakeCode	(0X401180);
	MakeName	(0X401180,	"nullsub_1");
	MakeArray	(0X401182,	0XE);
	MakeCode	(0X401190);
	MakeCode	(x=0X401195);
	OpHex		(x,	1);
	MakeCode	(x=0X4011A6);
	OpOff		(x,	1,	0);
	OpOff		(x,	129,	0);
	MakeCode	(x=0X4011BF);
	OpHex		(x,	1);
	MakeArray	(0X4011C6,	0X2);
	MakeCode	(x=0X4011C8);
	OpHex		(x,	1);
	MakeName	(0X4011C8,	".term_proc");
	MakeCode	(x=0X4011D1);
	OpHex		(x,	1);
	MakeStr		(0X4011E0,	0X4011EC);
	MakeName	(0X4011E0,	"s");
	MakeStr		(0X4011EC,	0X4011EF);
	MakeName	(0X4011EC,	"aD");
	MakeStr		(0X4011F0,	0X401210);
	MakeName	(0X4011F0,	"aSorryThatSNotA");
	MakeStr		(0X401210,	0X40121F);
	MakeName	(0X401210,	"aInputNumbers_");
	MakeStr		(0X40121F,	0X401237);
	MakeName	(0X40121F,	"aGotInputVerify");
	MakeStr		(0X401237,	0X401249);
	MakeName	(0X401237,	"aSorryIncorrect");
	MakeStr		(0X401249,	0X401252);
	MakeName	(0X401249,	"aSuccess");
	MakeStr		(0X401252,	0X401264);
	MakeName	(0X401252,	"format");
	MakeQword	(0X601E28);
	MakeQword	(0X601E38);
	MakeQword	(0X601E48);
	MakeQword	(x=0X601FE0);
	OpOff		(x,	0,	0);
	OpOff		(x,	128,	0);
	MakeName	(0X601FE0,	"__gmon_start___ptr");
	MakeArray	(0X601FE8,	0X18);
	MakeQword	(x=0X602000);
	OpOff		(x,	0,	0);
	OpOff		(x,	128,	0);
	MakeQword	(x=0X602008);
	OpOff		(x,	0,	0);
	OpOff		(x,	128,	0);
	MakeQword	(x=0X602010);
	OpOff		(x,	0,	0);
	OpOff		(x,	128,	0);
	MakeQword	(x=0X602018);
	OpOff		(x,	0,	0);
	OpOff		(x,	128,	0);
	MakeQword	(x=0X602020);
	OpOff		(x,	0,	0);
	OpOff		(x,	128,	0);
	MakeQword	(x=0X602028);
	OpOff		(x,	0,	0);
	OpOff		(x,	128,	0);
	MakeArray	(0X602030,	0X10);
	MakeByte	(0X602040);
	MakeArray	(0X602041,	0X7);
	MakeQword	(0X602048);
	MakeDword	(0X602050);
	MakeDword	(0X602054);
	MakeDword	(0X602058);
	MakeDword	(0X60205C);
	MakeDword	(0X602060);
	MakeArray	(0X602064,	0X4);
	MakeCode	(0X602068);
	MakeName	(0X602068,	"puts");
	MakeCode	(0X60206C);
	MakeName	(0X60206C,	"printf");
	MakeCode	(0X602070);
	MakeName	(0X602070,	"__libc_start_main");
	MakeCode	(0X602074);
	MakeName	(0X602074,	"calloc");
	MakeCode	(0X602078);
	MakeName	(0X602078,	"__isoc99_scanf");
	MakeCode	(0X60207C);
	MakeName	(0X60207C,	"exit");
	MakeCode	(0X602080);
	MakeName	(0X602080,	"__gmon_start__");
}

static Functions_0(void) {

	MakeFunction    (0X4004D0,0X4004E8);
	SetFunctionFlags(0X4004D0,0x4400);
	MakeFrame(0X4004D0, 0X8, 0, 0);
	MakeFunction    (0X400500,0X400506);
	SetFunctionFlags(0X400500,0x4c0);
	SetType(0X400500, "int puts(const char *s);");
	MakeFunction    (0X400510,0X400516);
	SetFunctionFlags(0X400510,0x4c0);
	SetType(0X400510, "int printf(const char *format, ...);");
	MakeFunction    (0X400520,0X400526);
	SetFunctionFlags(0X400520,0x4c0);
	MakeFunction    (0X400530,0X400536);
	SetFunctionFlags(0X400530,0x4c0);
	SetType(0X400530, "void *calloc(size_t nmemb, size_t size);");
	MakeFunction    (0X400540,0X400546);
	SetFunctionFlags(0X400540,0x4c0);
	MakeFunction    (0X400550,0X400556);
	SetFunctionFlags(0X400550,0x4c1);
	SetType(0X400550, "void exit(int status);");
	MakeFunction    (0X400560,0X40058A);
	SetFunctionFlags(0X400560,0x401);
	MakeFunction    (0X40058C,0X4005A3);
	SetFunctionFlags(0X40058C,0x4400);
	MakeFrame(0X40058C, 0X8, 0, 0);
	MakeFunction    (0X4005B0,0X400614);
	SetFunctionFlags(0X4005B0,0x4410);
	MakeFrame(0X4005B0, 0X10, 8, 0);
	MakeFunction    (0X400620,0X400642);
	SetFunctionFlags(0X400620,0x4410);
	MakeFrame(0X400620, 0, 8, 0);
	MakeFunction    (0X400706,0X4007CB);
	SetFunctionFlags(0X400706,0x4410);
	MakeFrame(0X400706, 0X38, 8, 0);
	MakeFunction    (0X4007CB,0X400CBB);
	SetFunctionFlags(0X4007CB,0x4410);
	MakeFrame(0X4007CB, 0X90, 8, 0);
	MakeLocal(0X4007CB, 0X400CBB, "[bp-0X8C]", "varOrder");
	MakeLocal(0X4007CB, 0X400CBB, "[bp-0X88]", "varNumbers");
	MakeFunction    (0X400CBB,0X400E23);
	SetFunctionFlags(0X400CBB,0x4410);
	MakeFrame(0X400CBB, 0X34, 8, 0);
	MakeFunction    (0X400E23,0X4010E2);
	SetFunctionFlags(0X400E23,0x411);
	MakeFrame(0X400E23, 0X70, 8, 0);
	MakeFunction    (0X401180,0X401182);
	SetFunctionFlags(0X401180,0x4440);
	MakeFunction    (0X401190,0X4011C6);
	SetFunctionFlags(0X401190,0x4410);
	MakeFrame(0X401190, 0X10, 8, 0);
	MakeFunction    (0X4011C8,0X4011D6);
	SetFunctionFlags(0X4011C8,0x4400);
	MakeFrame(0X4011C8, 0X8, 0, 0);
	MakeFunction    (0X602068,0X60206C);
	SetFunctionFlags(0X602068,0x400);
	SetType(0X602068, "int puts(const char *s);");
	MakeFunction    (0X60206C,0X602070);
	SetFunctionFlags(0X60206C,0x400);
	SetType(0X60206C, "int printf(const char *format, ...);");
	MakeFunction    (0X602070,0X602074);
	SetFunctionFlags(0X602070,0x400);
	MakeFunction    (0X602074,0X602078);
	SetFunctionFlags(0X602074,0x400);
	SetType(0X602074, "void *calloc(size_t nmemb, size_t size);");
	MakeFunction    (0X602078,0X60207C);
	SetFunctionFlags(0X602078,0x400);
	MakeFunction    (0X60207C,0X602080);
	SetFunctionFlags(0X60207C,0x401);
	SetType(0X60207C, "void exit(int status);");
	MakeFunction    (0X602080,0X602084);
	SetFunctionFlags(0X602080,0x400);
}

//------------------------------------------------------------------------
// Information about functions

static Functions(void) {

	Functions_0();
}

//------------------------------------------------------------------------
// Information about segment registers

static SegRegs(void) {
	SetRegEx(0X4004D0,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4004D0,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4004D0,"ds",0XD,3);
	SetRegEx(0X4004D0,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4004D0,"gs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4004F0,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4004F0,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4004F0,"ds",0XD,3);
	SetRegEx(0X4004F0,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4004F0,"gs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X400560,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X400560,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X400560,"ds",0XD,3);
	SetRegEx(0X400560,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X400560,"gs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4011C8,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4011C8,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4011C8,"ds",0XD,3);
	SetRegEx(0X4011C8,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4011C8,"gs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4011D8,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4011D8,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4011D8,"ds",0XD,3);
	SetRegEx(0X4011D8,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4011D8,"gs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X401264,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X401264,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X401264,"ds",0XD,3);
	SetRegEx(0X401264,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X401264,"gs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4012B0,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4012B0,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4012B0,"ds",0XD,3);
	SetRegEx(0X4012B0,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X4012B0,"gs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601E28,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601E28,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601E28,"ds",0XD,3);
	SetRegEx(0X601E28,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601E28,"gs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601E38,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601E38,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601E38,"ds",0XD,3);
	SetRegEx(0X601E38,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601E38,"gs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601E48,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601E48,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601E48,"ds",0XD,3);
	SetRegEx(0X601E48,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601E48,"gs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601FE0,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601FE0,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601FE0,"ds",0XD,3);
	SetRegEx(0X601FE0,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601FE0,"gs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601FE8,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601FE8,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601FE8,"ds",0XD,3);
	SetRegEx(0X601FE8,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X601FE8,"gs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X602030,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X602030,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X602030,"ds",0XD,3);
	SetRegEx(0X602030,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X602030,"gs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X602040,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X602040,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X602040,"ds",0XD,3);
	SetRegEx(0X602040,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X602040,"gs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X602068,"es",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X602068,"ss",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X602068,"ds",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X602068,"fs",0XFFFFFFFFFFFFFFFF,3);
	SetRegEx(0X602068,"gs",0XFFFFFFFFFFFFFFFF,3);
}

//------------------------------------------------------------------------
// Information about all patched bytes:

static Patches(void) {
}

//------------------------------------------------------------------------
// Call all byte feature functions:

static Bytes(void) {
	Bytes_0();
        EndTypeUpdating(UTP_STRUCT);
}

// End of file.
