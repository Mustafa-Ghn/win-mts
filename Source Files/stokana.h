//---------------------------------------------------------------------------

#ifndef stokanaH
#define stokanaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TfrmStokKarti : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TToolBar *ToolBar1;
    TToolButton *tbtnYENI;
    TToolButton *tbtnKAYDET;
    TToolButton *tbtnSIL;
    TToolButton *ToolButton4;
    TToolButton *tbtnAC;
    TImageList *ImageList1;
    TPageControl *PageControl1;
    TTabSheet *tabsheetGirisler;
    TTabSheet *tabsheetCikislar;
    TDBGrid *DBGrid1;
    TGroupBox *GroupBox2;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TLabel *Label15;
    TDBEdit *dbeditMaliyeti;
    TDBEdit *dbeditIsletmeKari;
    TDBEdit *dbeditIsletmeGideri;
    TDBEdit *dbeditAraToplam;
    TDBEdit *dbeditKDVTutari;
    TDBEdit *dbeditGenelToplam;
    TDBEdit *dbeditYuvarlama;
    TTabSheet *tabsheetUretimAgaci;
    TDBGrid *DBGrid3;
    TToolButton *ToolButton6;
    TToolButton *ToolButton7;
    TToolButton *ToolButton8;
    TDBGrid *DBGrid2;
    TPageControl *PageControl2;
    TTabSheet *TabSheet1;
    TLabel *Label1;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label2;
    TLabel *Label16;
    TLabel *Label17;
    TDBEdit *dbeditKod;
    TDBEdit *dbeditDevirMiktari;
    TDBEdit *dbeditKDVOrani;
    TDBEdit *dbeditAd;
    TDBEdit *dbeditBirimOrani;
    TDBEdit *dbeditStokDurum;
    TDBComboBox *dbcomboOlcuBirimi;
    TDBEdit *dbeditBirimFiyati;
    TDBComboBox *dbcomboDepartman;
    TDBComboBox *dbcomboCinsi;
    TTabSheet *TabSheet2;
    TDBGrid *DBGrid4;
    TLabel *Label18;
    TEdit *editAdaGore;
    TEdit *editKodaGore;
    TLabel *Label19;
    TMainMenu *MainMenu1;
    TMenuItem *dOSYA1;
    TMenuItem *Yeni1;
    TMenuItem *Kaydet1;
    TMenuItem *Sil1;
    TMenuItem *N1;
    TMenuItem *A1;
    TMenuItem *N2;
    TMenuItem *k1;
    TMenuItem *Rapor1;
    TMenuItem *MaliyetCetveli1;
    TMenuItem *MuaddelCetveli1;
    TDataSource *dsrcSTOKANA;
    TTable *tblSTOKANA;
    TDBRadioGroup *DBRadioGroup1;
    TStringField *tblSTOKANADEPARTMAN;
    TFloatField *tblSTOKANAKOD;
    TStringField *tblSTOKANAADI;
    TStringField *tblSTOKANAOLCU_BIRIMI;
    TFloatField *tblSTOKANABIRIM_ORANI;
    TFloatField *tblSTOKANABIRIM_FIYATI;
    TFloatField *tblSTOKANAKDV_ORANI;
    TFloatField *tblSTOKANADEVIR_MIKTARI;
    TFloatField *tblSTOKANASON_DURUM;
    TFloatField *tblSTOKANAMALIYETI;
    TFloatField *tblSTOKANAISLETME_KARI;
    TFloatField *tblSTOKANAISLETME_GIDERI;
    TFloatField *tblSTOKANAARA_TOPLAM;
    TFloatField *tblSTOKANAKDV_TUTARI;
    TFloatField *tblSTOKANAGENEL_TOPLAM;
    TFloatField *tblSTOKANAYUVARLAMA;
    TStringField *tblSTOKANACINSI;
    TStringField *tblSTOKANACINSI_KUTUSU;
    TTimer *Timer1;
    TQuery *queryKAYITKONTROL;
    TStringField *queryKAYITKONTROLDEPARTMAN;
    TFloatField *queryKAYITKONTROLKOD;
    TStringField *queryKAYITKONTROLCINSI_KUTUSU;
    TStringField *queryKAYITKONTROLCINSI;
    TStringField *queryKAYITKONTROLADI;
    TStringField *queryKAYITKONTROLOLCU_BIRIMI;
    TFloatField *queryKAYITKONTROLBIRIM_ORANI;
    TFloatField *queryKAYITKONTROLBIRIM_FIYATI;
    TFloatField *queryKAYITKONTROLKDV_ORANI;
    TFloatField *queryKAYITKONTROLDEVIR_MIKTARI;
    TFloatField *queryKAYITKONTROLSON_DURUM;
    TFloatField *queryKAYITKONTROLMALIYETI;
    TFloatField *queryKAYITKONTROLISLETME_KARI;
    TFloatField *queryKAYITKONTROLISLETME_GIDERI;
    TFloatField *queryKAYITKONTROLARA_TOPLAM;
    TFloatField *queryKAYITKONTROLKDV_TUTARI;
    TFloatField *queryKAYITKONTROLGENEL_TOPLAM;
    TFloatField *queryKAYITKONTROLYUVARLAMA;
    TStringField *tblSTOKANAINDEKS;
    TQuery *querySTOKLIST;
    TDataSource *dsrcSTOKLIST;
    TSpeedButton *SpeedButton1;
    TTable *tblURETIMANA;
    TStringField *tblURETIMANAURUNKODU;
    TStringField *tblURETIMANAMALZEMEKODU;
    TFloatField *tblURETIMANAMALZEMEMIKTARI;
    TDataSource *dsrcURETIMHAREKETI;
    TTable *tblURETIMHAREKETI;
    TFloatField *tblURETIMHAREKETIKOD;
    TStringField *tblURETIMHAREKETIADI;
    TFloatField *tblURETIMHAREKETIOLCUSU;
    TStringField *tblURETIMHAREKETIBIRIMI;
    TFloatField *tblURETIMHAREKETIMIKTAR;
    TFloatField *tblURETIMHAREKETIBIRIMFIYATI;
    TFloatField *tblURETIMHAREKETIKDV;
    TFloatField *tblURETIMHAREKETIKDVTUTARI;
    TFloatField *tblURETIMHAREKETITUTAR;
    TPopupMenu *popupURETIMRECETESI;
    TMenuItem *Sil2;
    TQuery *queryURETIMHAREKETI;
    TFloatField *queryURETIMHAREKETIKOD;
    TStringField *queryURETIMHAREKETIADI;
    TFloatField *queryURETIMHAREKETIOLCUSU;
    TStringField *queryURETIMHAREKETIBIRIMI;
    TFloatField *queryURETIMHAREKETIMIKTAR;
    TFloatField *queryURETIMHAREKETIBIRIMFIYATI;
    TFloatField *queryURETIMHAREKETIKDV;
    TFloatField *queryURETIMHAREKETIKDVTUTARI;
    TFloatField *queryURETIMHAREKETITUTAR;
    TQuery *querySQL;
    TStringField *querySQLURUNKODU;
    TStringField *querySQLMALZEMEKODU;
    TFloatField *querySQLMALZEMEMIKTARI;
    TToolButton *ToolButton1;
    TToolButton *tbtnKOPYALA;
    TMenuItem *Kopyala1;
    TDateField *tblSTOKANATARIH;
    TTimeField *tblSTOKANASAAT;
    TToolButton *ToolButton2;
    TMenuItem *TopluMakiyetMuaddelBasm1;
    TMenuItem *TabloyuBoalt1;
    TDataSource *dsrcSTOKDURUMCIKISI;
    TQuery *querySTOKDURUMCIKISI;
    TFloatField *querySTOKDURUMCIKISIHAREKETINDEKS;
    TBooleanField *querySTOKDURUMCIKISIHAREKETTURU;
    TStringField *querySTOKDURUMCIKISIBELGENO;
    TDateField *querySTOKDURUMCIKISITARIH;
    TStringField *querySTOKDURUMCIKISIDEPARTMAN;
    TFloatField *querySTOKDURUMCIKISISTOKKODU;
    TStringField *querySTOKDURUMCIKISISTOKADI;
    TFloatField *querySTOKDURUMCIKISIBIRIMFIYATI;
    TFloatField *querySTOKDURUMCIKISIMIKTAR;
    TFloatField *querySTOKDURUMCIKISITUTAR;
    TQuery *querySTOKDURUMGIRISI;
    TDataSource *dsrcSTOKDURUMGIRISI;
    TFloatField *querySTOKDURUMGIRISIHAREKETINDEKS;
    TBooleanField *querySTOKDURUMGIRISIHAREKETTURU;
    TStringField *querySTOKDURUMGIRISIBELGENO;
    TDateField *querySTOKDURUMGIRISITARIH;
    TStringField *querySTOKDURUMGIRISIDEPARTMAN;
    TFloatField *querySTOKDURUMGIRISISTOKKODU;
    TStringField *querySTOKDURUMGIRISISTOKADI;
    TFloatField *querySTOKDURUMGIRISIBIRIMFIYATI;
    TFloatField *querySTOKDURUMGIRISIMIKTAR;
    TFloatField *querySTOKDURUMGIRISITUTAR;
    TLabel *Label20;
    TDBComboBox *dbcomboMuaddelBirimi;
    TLabel *Label21;
    TDBEdit *dbeditMuaddelBirimOrani;
    TStringField *tblSTOKANAMUADDEL_BIRIMI;
    TFloatField *tblSTOKANAMUADDEL_BIRIM_ORANI;
    TStaticText *StaticText1;
    TStringField *querySTOKLISTINDEKS;
    TStringField *querySTOKLISTDEPARTMAN;
    TFloatField *querySTOKLISTKOD;
    TStringField *querySTOKLISTCINSI_KUTUSU;
    TStringField *querySTOKLISTCINSI;
    TStringField *querySTOKLISTADI;
    TStringField *querySTOKLISTOLCU_BIRIMI;
    TFloatField *querySTOKLISTBIRIM_ORANI;
    TStringField *querySTOKLISTMUADDEL_BIRIMI;
    TFloatField *querySTOKLISTMUADDEL_BIRIM_ORANI;
    TFloatField *querySTOKLISTBIRIM_FIYATI;
    TFloatField *querySTOKLISTKDV_ORANI;
    TFloatField *querySTOKLISTDEVIR_MIKTARI;
    TFloatField *querySTOKLISTSON_DURUM;
    TFloatField *querySTOKLISTMALIYETI;
    TFloatField *querySTOKLISTISLETME_KARI;
    TFloatField *querySTOKLISTISLETME_GIDERI;
    TFloatField *querySTOKLISTARA_TOPLAM;
    TFloatField *querySTOKLISTKDV_TUTARI;
    TFloatField *querySTOKLISTGENEL_TOPLAM;
    TFloatField *querySTOKLISTYUVARLAMA;
    TDateField *querySTOKLISTTARIH;
    TTimeField *querySTOKLISTSAAT;
    TQuery *querySTOKLISTESI;
    TDataSource *dsrcSTOKLISTESI;
    TStringField *querySTOKLISTESIINDEKS;
    TStringField *querySTOKLISTESIDEPARTMAN;
    TFloatField *querySTOKLISTESIKOD;
    TStringField *querySTOKLISTESICINSI_KUTUSU;
    TStringField *querySTOKLISTESICINSI;
    TStringField *querySTOKLISTESIADI;
    TStringField *querySTOKLISTESIOLCU_BIRIMI;
    TFloatField *querySTOKLISTESIBIRIM_ORANI;
    TStringField *querySTOKLISTESIMUADDEL_BIRIMI;
    TFloatField *querySTOKLISTESIMUADDEL_BIRIM_ORANI;
    TFloatField *querySTOKLISTESIBIRIM_FIYATI;
    TFloatField *querySTOKLISTESIKDV_ORANI;
    TFloatField *querySTOKLISTESIDEVIR_MIKTARI;
    TFloatField *querySTOKLISTESISON_DURUM;
    TFloatField *querySTOKLISTESIMALIYETI;
    TFloatField *querySTOKLISTESIISLETME_KARI;
    TFloatField *querySTOKLISTESIISLETME_GIDERI;
    TFloatField *querySTOKLISTESIARA_TOPLAM;
    TFloatField *querySTOKLISTESIKDV_TUTARI;
    TFloatField *querySTOKLISTESIGENEL_TOPLAM;
    TFloatField *querySTOKLISTESIYUVARLAMA;
    TDateField *querySTOKLISTESITARIH;
    TTimeField *querySTOKLISTESISAAT;
    TTabSheet *TabSheet3;
    TDBGrid *DBGrid5;
    TToolButton *tbtnFIYATGECMISI;
    TMenuItem *FiyatGemiListesineEkle1;
    TDataSource *dsrcFIYATGECMISI;
    TQuery *queryFIYATGECMISI;
    TStringField *queryFIYATGECMISIINDEKS;
    TDateField *queryFIYATGECMISITARIH;
    TFloatField *queryFIYATGECMISIFIYAT;
    TToolButton *ToolButton5;
    TPopupMenu *popupFIYATGECMISI;
    TMenuItem *Ekle1;
    TMenuItem *Sil3;
    TQuery *queryFIYATGECMISISIL;
    TComboBox *comboCinsi;
    TLabel *Label22;
    TBevel *Bevel1;
    TAnimate *Animate1;
    void __fastcall MalzemeSecimi(void);
    void __fastcall UrunSecimi(void);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall PageControl2Change(TObject *Sender);
    void __fastcall PageControl1Change(TObject *Sender);
    void __fastcall k1Click(TObject *Sender);
    void __fastcall DBRadioGroup1Change(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall dbcomboDepartmanKeyPress(TObject *Sender, char &Key);
    void __fastcall dbeditKodKeyPress(TObject *Sender, char &Key);
    void __fastcall dbcomboOlcuBirimiKeyPress(TObject *Sender, char &Key);
    void __fastcall dbeditBirimFiyatiKeyPress(TObject *Sender, char &Key);
    void __fastcall dbeditKDVOraniKeyPress(TObject *Sender, char &Key);
    void __fastcall dbcomboCinsiKeyPress(TObject *Sender, char &Key);
    void __fastcall dbeditAdKeyPress(TObject *Sender, char &Key);
    void __fastcall dbeditBirimOraniKeyPress(TObject *Sender, char &Key);
    void __fastcall dbeditDevirMiktariKeyPress(TObject *Sender, char &Key);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall Yeni1Click(TObject *Sender);
    void __fastcall Kaydet1Click(TObject *Sender);
    void __fastcall Sil1Click(TObject *Sender);
    void __fastcall tblSTOKANAAfterInsert(TDataSet *DataSet);
    void __fastcall IcerikDoldur(void);
    void __fastcall tblSTOKANAAfterPost(TDataSet *DataSet);
    void __fastcall dbcomboOlcuBirimiChange(TObject *Sender);
    void __fastcall A1Click(TObject *Sender);
    void __fastcall MaliyetCetveli1Click(TObject *Sender);
    void __fastcall MuaddelCetveli1Click(TObject *Sender);
    void __fastcall editAdaGoreChange(TObject *Sender);
    void __fastcall editKodaGoreChange(TObject *Sender);
    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall DBGrid4DblClick(TObject *Sender);
    void __fastcall Sil2Click(TObject *Sender);
    void __fastcall tblURETIMHAREKETIMIKTARChange(TField *Sender);
    void __fastcall dbeditBirimFiyatiChange(TObject *Sender);
    void __fastcall dbeditYuvarlamaChange(TObject *Sender);
    void __fastcall dbeditYuvarlamaKeyPress(TObject *Sender, char &Key);
    void __fastcall Kopyala1Click(TObject *Sender);
    void __fastcall TopluMakiyetMuaddelBasm1Click(TObject *Sender);
    void __fastcall TabloyuBoalt1Click(TObject *Sender);
    void __fastcall tblSTOKANABIRIM_FIYATIChange(TField *Sender);
    void __fastcall tblSTOKANADEVIR_MIKTARIChange(TField *Sender);
    void __fastcall dbcomboDepartmanChange(TObject *Sender);
    void __fastcall dbcomboMuaddelBirimiKeyPress(TObject *Sender,
          char &Key);
    void __fastcall dbeditMuaddelBirimOraniKeyPress(TObject *Sender,
          char &Key);
    void __fastcall dbcomboMuaddelBirimiChange(TObject *Sender);
    void __fastcall FiyatGemiListesineEkle1Click(TObject *Sender);
    void __fastcall Sil3Click(TObject *Sender);
    void __fastcall Ekle1Click(TObject *Sender);
    void __fastcall comboCinsiChange(TObject *Sender);
    void __fastcall DBGrid4KeyPress(TObject *Sender, char &Key);
    void __fastcall editAdaGoreClick(TObject *Sender);
    void __fastcall editKodaGoreClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmStokKarti(TComponent* Owner);
    void __fastcall StokMaliyetHesaplamasi(void);
    void __fastcall UretimAnaSil(void);
    void __fastcall UretimAnaOlustur(void);
    void __fastcall UretimRecetesiSifirla(void);
    void __fastcall UretimRecetesiOlustur(AnsiString Indeks);
    void __fastcall StokGirisListele(void);
    void __fastcall StokDurumunuHesapla(void);
    void __fastcall FiyatGecmisiGuncelle(void);
    void __fastcall StokGecmisiSil(void);
    void __fastcall ModulKisitlandirma(void);
    AnsiString __fastcall TurkishLowerCase(const AnsiString SourceString);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmStokKarti *frmStokKarti;
extern bool StokYeniKayit;
//---------------------------------------------------------------------------
#endif
