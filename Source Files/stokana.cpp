//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "anamenu.h"
#include "string.h"
#include "tarihsecimi.h"
#include "stdio.h"
#include "stokana.h"
#include "topludokum.h"
#include "departman.h"
#include "kartkopyala.h"
#include "olcu.h"
#include "parametre.h"
#include "uruncinsi.h"
#include "raporayar.h"
#include "stoklist.h"
#include "sifregiris.h"
#include "sifre.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmStokKarti *frmStokKarti;
bool StokYeniKayit = true;
//---------------------------------------------------------------------------
__fastcall TfrmStokKarti::TfrmStokKarti(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

// Stok Kart� Cinsi Malzeme Se�imi Yap�ld���nda...
void __fastcall TfrmStokKarti::MalzemeSecimi(void)
{
    dbeditMaliyeti->Enabled = false;
    dbeditIsletmeKari->Enabled = false;
    dbeditIsletmeGideri->Enabled = false;
    dbeditAraToplam->Enabled = false;
    dbeditKDVTutari->Enabled = false;
    dbeditGenelToplam->Enabled = false;
    dbeditYuvarlama->Enabled = false;
    DBGrid3->Enabled = false;
    DBGrid4->Enabled = false;
    editAdaGore->Enabled = false;
    editKodaGore->Enabled = false;
    PageControl2->ActivePageIndex = 0;
    PageControl1->ActivePageIndex = 0;

    StaticText1->Color = clBtnFace;
    DBGrid4->Color = clBtnFace;
    editAdaGore->Color = clBtnFace;
    editKodaGore->Color = clBtnFace;
    dbeditMaliyeti->Color = clBtnFace;
    dbeditIsletmeKari->Color = clBtnFace;
    dbeditIsletmeGideri->Color = clBtnFace;
    dbeditAraToplam->Color = clBtnFace;
    dbeditKDVTutari->Color = clBtnFace;
    dbeditGenelToplam->Color = clBtnFace;
    dbeditYuvarlama->Color = clBtnFace;
    DBGrid3->Color = clBtnFace;
    DBGrid3->Columns->Items[0]->Color = clBtnFace;
    DBGrid3->Columns->Items[1]->Color = clBtnFace;
    DBGrid3->Columns->Items[2]->Color = clBtnFace;
    DBGrid3->Columns->Items[3]->Color = clBtnFace;
    DBGrid3->Columns->Items[5]->Color = clBtnFace;
    DBGrid3->Columns->Items[6]->Color = clBtnFace;
    DBGrid3->Columns->Items[7]->Color = clBtnFace;
    DBGrid3->Columns->Items[8]->Color = clBtnFace;
    ToolButton6->Enabled = false;
    ToolButton7->Enabled = false;
    tbtnFIYATGECMISI->Enabled = false;
    FiyatGemiListesineEkle1->Enabled = false;
    MaliyetCetveli1->Enabled = false;
    MuaddelCetveli1->Enabled = false;

    // Giris DBGrid'ine ait kolonlar yap�lan�yor...
    DBGrid1->Columns->Items[0]->Width = 100;
    DBGrid1->Columns->Items[1]->Width = 100;
    DBGrid1->Columns->Items[2]->Visible = false;
    DBGrid1->Columns->Items[3]->Visible = false;
    DBGrid1->Columns->Items[4]->Width = 100;
    DBGrid1->Columns->Items[5]->Width = 150;
    DBGrid1->Columns->Items[6]->Width = 150;
}
//---------------------------------------------------------------------------

// Stok Kart� Cinsi �r�n Se�imi Yap�ld���nda...
void __fastcall TfrmStokKarti::UrunSecimi(void)
{
    bool myEnabled;

    dbeditMaliyeti->Enabled = true;
    dbeditIsletmeKari->Enabled = true;
    dbeditIsletmeGideri->Enabled = true;
    dbeditAraToplam->Enabled = true;
    dbeditKDVTutari->Enabled = true;
    dbeditGenelToplam->Enabled = true;
    dbeditYuvarlama->Enabled = true;
    DBGrid3->Enabled = true;
    DBGrid4->Enabled = true;
    editAdaGore->Enabled = true;
    editKodaGore->Enabled = true;

    StaticText1->Color = clBtnHighlight;
    DBGrid4->Color = clWindow;
    editAdaGore->Color = clWindow;
    editKodaGore->Color = clWindow;
    dbeditMaliyeti->Color = clWindow;
    dbeditIsletmeKari->Color = clWindow;
    dbeditIsletmeGideri->Color = clWindow;
    dbeditAraToplam->Color = clWindow;
    dbeditKDVTutari->Color = clWindow;
    dbeditGenelToplam->Color = clWindow;
    dbeditYuvarlama->Color = clWindow;
    DBGrid3->Color = clWindow;
    DBGrid3->Columns->Items[0]->Color = clInfoBk;
    DBGrid3->Columns->Items[1]->Color = clInfoBk;
    DBGrid3->Columns->Items[2]->Color = clInfoBk;
    DBGrid3->Columns->Items[3]->Color = clInfoBk;
    DBGrid3->Columns->Items[5]->Color = clInfoBk;
    DBGrid3->Columns->Items[6]->Color = clInfoBk;
    DBGrid3->Columns->Items[7]->Color = clInfoBk;
    DBGrid3->Columns->Items[8]->Color = clInfoBk;

    // Rapor Se�imi Aktif mi, Pasif mi?
    frmSifre->querySIFREKONTROL->Active = tblSTOKANA->Active;
    myEnabled = frmYoneticiModulu->KarakterAyikla(frmSifre->querySIFREKONTROLRAPOR_SECIMI->Value, 4) - '0';
    ToolButton6->Enabled = myEnabled;
    ToolButton7->Enabled = myEnabled;
    MaliyetCetveli1->Enabled = myEnabled;
    MuaddelCetveli1->Enabled = myEnabled;

    tbtnFIYATGECMISI->Enabled = true;
    FiyatGemiListesineEkle1->Enabled = true;

    // Giris DBGrid'ine ait kolonlar yap�lan�yor...
    DBGrid1->Columns->Items[0]->Width = 75;
    DBGrid1->Columns->Items[1]->Width = 75;
    DBGrid1->Columns->Items[2]->Visible = true;
    DBGrid1->Columns->Items[3]->Visible = true;
    DBGrid1->Columns->Items[4]->Width = 70;
    DBGrid1->Columns->Items[5]->Width = 100;
    DBGrid1->Columns->Items[6]->Width = 100;

    // �retim Ana ve �retim hareketi table a��l�yor..
    tblURETIMHAREKETI->Open();
    tblURETIMANA->Open();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::IcerikDoldur(void)
{
    // Departman ComboBox'�na kay�t ekleniyor...
    dbcomboDepartman->Items->Clear();
    frmDepartman->tblDEPARTMAN->Open();
    frmDepartman->tblDEPARTMAN->First();
    while (!frmDepartman->tblDEPARTMAN->Eof) {
        dbcomboDepartman->Items->Add(frmDepartman->tblDEPARTMANDEPARTMAN->Value);
        frmDepartman->tblDEPARTMAN->Next();
    }
    frmDepartman->tblDEPARTMAN->Close();

    // �r�n Cinsi ComboBox'�na kay�t ekleniyor...
    frmUrunCinsi->tblURUNCINSI->Open();
    frmUrunCinsi->tblURUNCINSI->First();
    dbcomboCinsi->Items->Clear();
    comboCinsi->Items->Clear();
    dbcomboCinsi->Items->Add("MALZEME");
    comboCinsi->Items->Add("");
    comboCinsi->Items->Add("MALZEME");
    while (!frmUrunCinsi->tblURUNCINSI->Eof) {
        dbcomboCinsi->Items->Add(frmUrunCinsi->tblURUNCINSIURUNCINSI->Value);
        comboCinsi->Items->Add(frmUrunCinsi->tblURUNCINSIURUNCINSI->Value);
        frmUrunCinsi->tblURUNCINSI->Next();
    }
    frmUrunCinsi->tblURUNCINSI->Close();

    // �l�� Birimi ComboBox'�na kay�t ekleniyor...
    dbcomboOlcuBirimi->Items->Clear();
    frmOlcuBirimi->tblOLCU->Open();
    frmOlcuBirimi->tblOLCU->First();
    while (!frmOlcuBirimi->tblOLCU->Eof) {
        dbcomboOlcuBirimi->Items->Add(frmOlcuBirimi->tblOLCUTANIMLAMA->Value);
        frmOlcuBirimi->tblOLCU->Next();
    }
    frmOlcuBirimi->tblOLCU->Close();

    // Muaddel �l�� Birimi ComboBox'�na kay�t ekleniyor...
    dbcomboMuaddelBirimi->Items->Clear();
    frmOlcuBirimi->tblOLCU->Open();
    frmOlcuBirimi->tblOLCU->First();
    while (!frmOlcuBirimi->tblOLCU->Eof) {
        dbcomboMuaddelBirimi->Items->Add(frmOlcuBirimi->tblOLCUTANIMLAMA->Value);
        frmOlcuBirimi->tblOLCU->Next();
    }
    frmOlcuBirimi->tblOLCU->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::FormShow(TObject *Sender)
{
    frmAnaMenu->Database->Connected = true;
    frmSifre->querySIFREKONTROL->Close();
    frmSifre->querySIFREKONTROL->Open();
    Timer1->Enabled = true;
    IcerikDoldur();
    DBRadioGroup1->ItemIndex = 0;
    DBRadioGroup1Change(Sender);
    UretimRecetesiSifirla();

    // Kont�r bittiyse �al��mayacak ....
    frmAnaMenu->GirisIzni();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::PageControl2Change(TObject *Sender)
{
    switch (DBRadioGroup1->ItemIndex) {
        case 0:
            PageControl2->ActivePageIndex = 0;
            break;
        case 1:
            PageControl1->ActivePageIndex = 2;
            break;
        default:
            PageControl2->ActivePageIndex = 0;
    }

    if (PageControl2->ActivePageIndex == 1) {
        querySTOKLISTESI->Close();
        querySTOKLISTESI->ParamByName("DEPARTMAN")->AsString = dbcomboDepartman->Text;
        querySTOKLISTESI->ParamByName("KOD")->AsFloat = NULL;
        querySTOKLISTESI->ParamByName("ADI")->AsString = "%"+editAdaGore->Text+"%";
        querySTOKLISTESI->ParamByName("CINSI")->AsString = "%"+comboCinsi->Text+"%";
        querySTOKLISTESI->Open();
        editKodaGore->Clear();
        editAdaGore->Clear();
        editKodaGore->Color = clScrollBar;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::PageControl1Change(TObject *Sender)
{
    switch (PageControl1->ActivePageIndex) {
        case 0:
        case 1:
            PageControl2->ActivePageIndex = 0;
            break;
        case 2:
            if (DBRadioGroup1->ItemIndex == 0)
                PageControl1->ActivePageIndex = 0;
            break;
        case 3:
            break;
        default:
            PageControl1->ActivePageIndex = 0;
            break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::k1Click(TObject *Sender)
{
    frmStokKarti->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::DBRadioGroup1Change(TObject *Sender)
{
    switch (DBRadioGroup1->ItemIndex) {
        case 0:
            MalzemeSecimi();
            break;
        case 1:
            UrunSecimi();
            break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    querySTOKLIST->Close();
    queryKAYITKONTROL->Close();
    tblURETIMHAREKETI->Close();
    tblURETIMANA->Close();
    queryURETIMHAREKETI->Close();
    querySTOKDURUMGIRISI->Close();
    querySTOKDURUMCIKISI->Close();

    tblSTOKANA->Cancel();
    tblSTOKANA->Close();
    frmAnaMenu->Database->Connected = false;
    Timer1->Enabled = false;    
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbcomboDepartmanKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbeditKodKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbcomboOlcuBirimiKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbeditBirimFiyatiKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbeditKDVOraniKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbcomboCinsiKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbeditAdKeyPress(TObject *Sender, char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbeditBirimOraniKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbeditDevirMiktariKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::FiyatGecmisiGuncelle(void)
{
    queryFIYATGECMISI->Close();
    queryFIYATGECMISI->ParamByName("INDEKS")->AsString = tblSTOKANAINDEKS->Value;
    queryFIYATGECMISI->Open();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::StokGirisListele(void)
{
    if (DBRadioGroup1->ItemIndex == 1) {
        querySTOKDURUMGIRISI->Close();
        querySTOKDURUMGIRISI->SQL->Clear();
        querySTOKDURUMGIRISI->SQL->Add("SELECT * FROM STOKDURUMU");
        querySTOKDURUMGIRISI->SQL->Add("WHERE HAREKETTURU=TRUE AND (");

        // Burada b�t�n �retim a�ac�na ait kalemler listelenmesi listelenir...
        tblURETIMHAREKETI->Open();
        tblURETIMHAREKETI->First();
        querySTOKDURUMGIRISI->SQL->Add("(DEPARTMAN = '"+tblSTOKANADEPARTMAN->Value
            +"' AND STOKKODU="+FloatToStr(tblURETIMHAREKETIKOD->Value)+")");
        tblURETIMHAREKETI->Next();
        while (!tblURETIMHAREKETI->Eof) {
            querySTOKDURUMGIRISI->SQL->Add(" OR (DEPARTMAN ='"+tblSTOKANADEPARTMAN->Value
                +"' AND STOKKODU="+FloatToStr(tblURETIMHAREKETIKOD->Value)+")");
            tblURETIMHAREKETI->Next();
        }
        tblURETIMHAREKETI->First();
        querySTOKDURUMGIRISI->SQL->Add(")");
        // ----------------------------------------------- Burada bitiyor...

        querySTOKDURUMGIRISI->SQL->Add("ORDER BY TARIH DESC");
        querySTOKDURUMGIRISI->Open();
    }
    else {
        querySTOKDURUMGIRISI->Close();
        querySTOKDURUMGIRISI->SQL->Clear();
        querySTOKDURUMGIRISI->SQL->Add("SELECT * FROM STOKDURUMU");
        querySTOKDURUMGIRISI->SQL->Add("WHERE HAREKETTURU=TRUE AND ");
        querySTOKDURUMGIRISI->SQL->Add("(DEPARTMAN='"+tblSTOKANADEPARTMAN->Value
            +"' AND STOKKODU="+FloatToStr(tblSTOKANAKOD->Value)+")");
        querySTOKDURUMGIRISI->SQL->Add("ORDER BY TARIH DESC");
        querySTOKDURUMGIRISI->Open();
    }
}
//---------------------------------------------------------------------------

AnsiString __fastcall TfrmStokKarti::TurkishLowerCase(const AnsiString SourceString)
{
    /* ****************************************************************
    T�rk�e alfabeyi b�y�tme ve k���ltme fonksiyonu yaz�lacak....
    ��lerin yo�unlu�undan yap�lamad�... Gelecekteki benim dikkatime ...
    �afak: 450 - 17 �ubat 2002 Pazar
    ---------------------------------------------------------------- */
/*
    int Counter = 0, AlhabetCounter = 0;
    AnsiString BigAlphabet = "������I";
    AnsiString SmallAlphabet = "���i���";
    AnsiString ProcessString;

    ProcessString = SourceString;
    Counter = 0;
    while (ProcessString[Counter] != NULL) {
        AlhabetCounter = 0;
        while (BigAlphabet[AlhabetCounter] != NULL) {
            if (ProcessString[Counter] == BigAlphabet[AlhabetCounter])
                ;
        }
        ++Counter;
    }                                          */
    return SourceString;
}
//---------------------------------------------------------------------------
void __fastcall TfrmStokKarti::ModulKisitlandirma(void)
{
    bool myEnabled;

    frmSifre->querySIFREKONTROL->Active = true;
    myEnabled = frmYoneticiModulu->KarakterAyikla(frmSifre->querySIFREKONTROLSTOK_KARTI->Value, 5) - '0';

    // Stok Kart� K�s�tlamd�rma Kontrol�
    if (myEnabled == false) {
        Yeni1->Enabled = false;
        Kaydet1->Enabled = false;
        Sil1->Enabled = false;
        Kopyala1->Enabled = false;
        FiyatGemiListesineEkle1->Enabled = false;
        tbtnYENI->Enabled = false;
        tbtnKAYDET->Enabled = false;
        tbtnSIL->Enabled = false;
        tbtnKOPYALA->Enabled = false;
        tbtnFIYATGECMISI->Enabled = false;

        // Fiyat Ge�mi�ine Ait PopupMenu ��elerini pasif et
        Ekle1->Enabled = false;
        Sil3->Enabled = false;
        // --------------------------------------- Kod Sonu
    }
    else {
        if (frmYoneticiModulu->KarakterAyikla(frmSifre->querySIFREKONTROLSTOK_KARTI->Value, 6) - '0' == true) {
            Yeni1->Enabled = true;
            tbtnYENI->Enabled = true;
        }
        else {
            Yeni1->Enabled = false;
            tbtnYENI->Enabled = false;
        }
        if (frmYoneticiModulu->KarakterAyikla(frmSifre->querySIFREKONTROLSTOK_KARTI->Value, 7) - '0' == true) {
            Sil1->Enabled = tblSTOKANA->Active;
            tbtnSIL->Enabled = tblSTOKANA->Active;
        }
        else {
            Sil1->Enabled = false;
            tbtnSIL->Enabled = false;
        }

        Kaydet1->Enabled = tblSTOKANA->Active;
        tbtnKAYDET->Enabled = tblSTOKANA->Active;
        Kopyala1->Enabled = tblSTOKANA->Active;
        tbtnKOPYALA->Enabled = tblSTOKANA->Active;
        FiyatGemiListesineEkle1->Enabled = tblSTOKANA->Active;
        tbtnFIYATGECMISI->Enabled = tblSTOKANA->Active;

        // Fiyat Ge�mi�ine Ait PopupMenu ��elerini pasif et
        Ekle1->Enabled = tblSTOKANA->Active;
        Sil3->Enabled = tblSTOKANA->Active;
        // --------------------------------------- Kod Sonu
    }
}

void __fastcall TfrmStokKarti::Timer1Timer(TObject *Sender)
{
    dbcomboOlcuBirimi->Enabled = tblSTOKANA->Active;
    dbcomboMuaddelBirimi->Enabled = tblSTOKANA->Active;
    dbeditMuaddelBirimOrani->Enabled = tblSTOKANA->Active;
    dbeditBirimFiyati->Enabled = tblSTOKANA->Active;
    dbeditKDVOrani->Enabled = tblSTOKANA->Active;
    dbcomboCinsi->Enabled = tblSTOKANA->Active;
    dbeditAd->Enabled = tblSTOKANA->Active;
    dbeditBirimOrani->Enabled = tblSTOKANA->Active;
    dbeditDevirMiktari->Enabled = tblSTOKANA->Active;
    dbeditStokDurum->Enabled = tblSTOKANA->Active;
    DBRadioGroup1->Enabled = tblSTOKANA->Active;
    frmSifre->querySIFREKONTROL->Active = tblSTOKANA->Active;

    if (StokYeniKayit == false && tblSTOKANA->Active == true) {
        querySTOKDURUMCIKISI->Active = true;
        querySTOKDURUMGIRISI->Active = true;
        queryFIYATGECMISI->Active = true;
    }
    else {
        querySTOKDURUMCIKISI->Active = false;
        querySTOKDURUMGIRISI->Active = false;
        queryFIYATGECMISI->Active = false;
    }

    if (tblSTOKANA->Active == true)
        frmStokKarti->Caption = "Stok Kart� - [ "+tblSTOKANADEPARTMAN->Value
            +" \\ "+tblSTOKANAADI->Value+" ]";
    else
        frmStokKarti->Caption = "Stok Kart�";

    // Stok kodu numaras� butonunu otomatik aktif et.
    if (dbcomboDepartman->Text.Length() != 0) {
        if (StokYeniKayit == true)
           SpeedButton1->Enabled = tblSTOKANA->Active;
        else
            SpeedButton1->Enabled = false;
    }
    else
        SpeedButton1->Enabled = false;

    // Eski Stok Kart�nda stok kodunun de�i�memesini sa�layan kod...
    if (tblSTOKANA->Active == true && StokYeniKayit == true) {
        dbeditKod->ReadOnly = true;
        dbcomboDepartman->Enabled = true;
    }
    else {
        dbeditKod->ReadOnly = false;
        dbcomboDepartman->Enabled = false;
    }

    // �retim re�etesi silindi�inde men�y� disable ediliyor...
    if (tblURETIMHAREKETI->Active == true) {
        if (tblURETIMHAREKETI->RecordCount <= 0)
            Sil2->Enabled = false;
    }

    ModulKisitlandirma();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::Yeni1Click(TObject *Sender)
{
    int nDeger;

    if (tblSTOKANA->Active == true)
    nDeger = Application->MessageBox("�nceki de�i�iklikler kay�t edilsin mi?", "Kay�t Onay�",
        MB_YESNOCANCEL + MB_ICONQUESTION);

    if (nDeger == IDYES)
        Kaydet1Click(Sender);
    else if (nDeger == IDCANCEL)
        goto IPTAL;

    tblSTOKANA->Cancel();
    tblSTOKANA->Close();
    tblSTOKANA->Open();
    tblSTOKANA->Filtered = false;
    tblSTOKANA->Insert();
    tblSTOKANA->Edit();
    DBRadioGroup1->ItemIndex = 0;
    UretimRecetesiSifirla();
    StokGirisListele();
IPTAL:
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::Kaydet1Click(TObject *Sender)
{
    TDateTime Zaman;

    // Kay�t kontrol i�lemi yap�l�yor...
    queryKAYITKONTROL->ParamByName("DEPARTMAN")->AsString = tblSTOKANADEPARTMAN->Value;
    queryKAYITKONTROL->ParamByName("KOD")->AsInteger = tblSTOKANAKOD->Value;
    queryKAYITKONTROL->ExecSQL();
    queryKAYITKONTROL->Open();

    if (queryKAYITKONTROLDEPARTMAN->Value.Length() != 0 && StokYeniKayit == true)
        Application->MessageBoxA("Bu stok kodu daha �nce kullan�lm��.\nTavsiyem, yeni bir stok kodu giriniz.",
            "Uyar� Mesaj�", MB_OK + MB_ICONEXCLAMATION);
    else if (dbcomboDepartman->Text.Length() == 0 || dbeditKod->Text.Length() == 0 || dbcomboCinsi->Text.Length() == 0)
        Application->MessageBoxA("Departman, Stok Cinsi veya Stok Kodu girmeden kay�t yapmay� unutun !..",
            "Uyar� Mesaj�", MB_OK + MB_ICONEXCLAMATION);
    else {
        // Stok Table Kay�t Ediliyor...
        if (StokYeniKayit == true) {
            tblSTOKANA->Edit();
            tblSTOKANATARIH->Value = Zaman.CurrentDate();
            tblSTOKANA->Edit();
            tblSTOKANASAAT->Value = Zaman.CurrentTime();
        }
        tblSTOKANA->Edit();
        tblSTOKANAINDEKS->Value = tblSTOKANADEPARTMAN->Value + FloatToStr(tblSTOKANAKOD->Value);
        tblSTOKANA->Edit();
        tblSTOKANA->Post();
        // �retim Re�etesi Kaydediliyor...
        if (DBRadioGroup1->ItemIndex == 1) {
            UretimAnaSil();
            tblURETIMHAREKETI->Close();
            tblURETIMHAREKETI->Open();
            UretimAnaOlustur();
        }
        StokGirisListele();
        FiyatGecmisiGuncelle();
    }
    queryKAYITKONTROL->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::Sil1Click(TObject *Sender)
{
    int nDeger;

    nDeger = Application->MessageBox("Kayd� silmek istedi�inize emin misiniz?", "Silme onay�",
        MB_YESNO + MB_ICONQUESTION);

    if (nDeger == IDYES) {
        if (DBRadioGroup1->ItemIndex == 1)
            UretimAnaSil();

        tblSTOKANA->Delete();
        DBRadioGroup1->ItemIndex = 0;
        PageControl1->ActivePageIndex = 0;
        PageControl2->ActivePageIndex = 0;
        tblSTOKANA->Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::tblSTOKANAAfterInsert(TDataSet *DataSet)
{
    StokYeniKayit = true; // �lk kay�t an�nda bu de�i�ken true de�erini al�r.
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::tblSTOKANAAfterPost(TDataSet *DataSet)
{
    StokYeniKayit = false; // Art�k bu stok kodu eski bir kay�t olmu� olur.
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbcomboOlcuBirimiChange(TObject *Sender)
{
    frmOlcuBirimi->tblOLCU->Open();
    frmOlcuBirimi->tblOLCU->RecNo = dbcomboOlcuBirimi->ItemIndex+1;
    tblSTOKANA->Edit();
    tblSTOKANABIRIM_ORANI->Value = frmOlcuBirimi->tblOLCUBIRIM_ORANI->Value;
    frmOlcuBirimi->tblOLCU->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::A1Click(TObject *Sender)
{
    frmStokListesi->Caption = "Stok Listesi [Stok Kart�]";
    frmStokListesi->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::MaliyetCetveli1Click(TObject *Sender)
{
    Kaydet1Click(Sender);
    frmRaporSecimi->RadioGroup1->ItemIndex = 0;
    frmRaporSecimi->RadioGroup1Click(Sender);
    frmRaporSecimi->Show();

    frmRaporSecimi->comboDepartmanBaslangic->ItemIndex = dbcomboDepartman->ItemIndex + 1;
    frmRaporSecimi->comboStokCinsiBaslangic->ItemIndex = dbcomboCinsi->ItemIndex + 1;
    frmRaporSecimi->editBaslangicStokKodu->Text = FloatToStr(tblSTOKANAKOD->Value);
    frmRaporSecimi->editBaslangicStokAdi->Text = tblSTOKANAADI->Value;
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::MuaddelCetveli1Click(TObject *Sender)
{
    Kaydet1Click(Sender);
    frmRaporSecimi->RadioGroup1->ItemIndex = 1;
    frmRaporSecimi->RadioGroup1Click(Sender);
    frmRaporSecimi->Show();

    frmRaporSecimi->comboStokCinsiBaslangic->ItemIndex = dbcomboCinsi->ItemIndex + 1;
    frmRaporSecimi->comboDepartmanBaslangic->ItemIndex = dbcomboDepartman->ItemIndex + 1;
    frmRaporSecimi->editBaslangicStokKodu->Text = FloatToStr(tblSTOKANAKOD->Value);
    frmRaporSecimi->editBaslangicStokAdi->Text = tblSTOKANAADI->Value;
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::editAdaGoreChange(TObject *Sender)
{
    Animate1->Active = true;
    querySTOKLISTESI->Close();
    querySTOKLISTESI->ParamByName("DEPARTMAN")->AsString = dbcomboDepartman->Text;
    querySTOKLISTESI->ParamByName("KOD")->AsFloat = NULL;
    querySTOKLISTESI->ParamByName("CINSI")->AsString = "%"+comboCinsi->Text+"%";
    querySTOKLISTESI->ParamByName("ADI")->AsString = "%"+editAdaGore->Text+"%";
    querySTOKLISTESI->Open();
    Animate1->Active = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::editKodaGoreChange(TObject *Sender)
{
    if (editKodaGore->Text.Length() != 0) {
        Animate1->Active = true;
        querySTOKLISTESI->Close();
        querySTOKLISTESI->ParamByName("DEPARTMAN")->AsString = dbcomboDepartman->Text;
        querySTOKLISTESI->ParamByName("KOD")->AsFloat = StrToFloat(editKodaGore->Text);
        querySTOKLISTESI->ParamByName("CINSI")->AsString = "%"+comboCinsi->Text+"%";
        querySTOKLISTESI->ParamByName("ADI")->AsString = NULL;
        querySTOKLISTESI->Open();
        Animate1->Active = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::SpeedButton1Click(TObject *Sender)
{
    querySTOKLIST->Close();
    querySTOKLIST->SQL->Clear();
    querySTOKLIST->SQL->Add("SELECT * FROM STOKANA");
    querySTOKLIST->SQL->Add("WHERE DEPARTMAN='"+dbcomboDepartman->Text+"'");
    querySTOKLIST->SQL->Add("ORDER BY KOD DESC");
    querySTOKLIST->ExecSQL();
    querySTOKLIST->Open();

    querySTOKLIST->First();
    tblSTOKANA->Edit();
    tblSTOKANAKOD->Value = querySTOKLISTKOD->Value+1;
    querySTOKLIST->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::DBGrid4DblClick(TObject *Sender)
{
    if (querySTOKLISTESIKOD->Value == tblSTOKANAKOD->Value)
        Application->MessageBoxA("�r�n kodu ile malzeme kodu ayn� olamaz.",
            "Uyar� Mesaj�", MB_OK + MB_ICONEXCLAMATION);
    else {
        // Yeni bir malzeme eklemenin kodlar�....
        tblURETIMHAREKETI->Open();
        tblURETIMHAREKETI->Insert();
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIKOD->Value = querySTOKLISTESIKOD->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIADI->Value = querySTOKLISTESIADI->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIOLCUSU->Value = querySTOKLISTESIMUADDEL_BIRIM_ORANI->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIBIRIMI->Value = querySTOKLISTESIMUADDEL_BIRIMI->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIBIRIMFIYATI->Value = querySTOKLISTESIBIRIM_FIYATI->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIKDV->Value = querySTOKLISTESIKDV_ORANI->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIKDVTUTARI->Value = querySTOKLISTESIKDV_TUTARI->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETITUTAR->Value = 0;
        tblURETIMHAREKETI->Post();
        // �retim re�etesi men�s� aktif eden kod.
        Sil2->Enabled = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::Sil2Click(TObject *Sender)
{
    int nDeger;

    nDeger = Application->MessageBox("Kayd� silmek istedi�inize emin misiniz?", "Silme onay�",
        MB_YESNO + MB_ICONQUESTION);

    if (nDeger == IDYES) {
        tblURETIMHAREKETI->Delete();
        StokMaliyetHesaplamasi();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::tblURETIMHAREKETIMIKTARChange(
      TField *Sender)
{
    if (tblURETIMHAREKETIBIRIMFIYATI->Value != 0) {
        // Girilen miktara g�re fiyat hesaplamas�...
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETITUTAR->Value =
            (tblURETIMHAREKETIBIRIMFIYATI->Value /
            tblURETIMHAREKETIOLCUSU->Value) * tblURETIMHAREKETIMIKTAR->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIKDVTUTARI->Value = tblURETIMHAREKETITUTAR->Value /
            100 * tblURETIMHAREKETIKDV->Value;
        tblURETIMHAREKETI->Post();
    }
    tblURETIMHAREKETI->Edit();
    if (tblSTOKANA->Active == true)
        StokMaliyetHesaplamasi();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::UretimRecetesiOlustur(AnsiString Indeks)
{
    querySQL->Close();
    querySQL->SQL->Clear();
    querySQL->SQL->Add("SELECT * FROM URUNANA");
    querySQL->SQL->Add("WHERE URUNKODU='"+Indeks+"'");
    querySQL->ExecSQL();

    querySQL->Open();
    querySQL->First();

    tblURETIMHAREKETI->Open();
    while (!querySQL->Eof) {
        // Burada i�lemler ba�l�yor...
        querySTOKLIST->Close(); // Malzeme detay� buradan itibaren getirliyor.
        querySTOKLIST->SQL->Clear();
        querySTOKLIST->SQL->Add("SELECT * FROM STOKANA");
        querySTOKLIST->SQL->Add("WHERE INDEKS='"+querySQLMALZEMEKODU->Value+"'");
        querySTOKLIST->ExecSQL();
        querySTOKLIST->Open();

        tblURETIMHAREKETI->Insert();
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIKOD->Value = querySTOKLISTKOD->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIADI->Value = querySTOKLISTADI->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIOLCUSU->Value = querySTOKLISTMUADDEL_BIRIM_ORANI->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIBIRIMI->Value = querySTOKLISTMUADDEL_BIRIMI->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIBIRIMFIYATI->Value = querySTOKLISTBIRIM_FIYATI->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIKDV->Value = querySTOKLISTKDV_ORANI->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIKDVTUTARI->Value = querySTOKLISTKDV_TUTARI->Value;
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETITUTAR->Value = 0;
        // Uretim anadaki miktar fiyat� girilmesi maliyet tablosunda hesaplamaya neden olur.
        tblURETIMHAREKETI->Edit();
        tblURETIMHAREKETIMIKTAR->Value = querySQLMALZEMEMIKTARI->Value;
        // Burada son buluyor...
        tblURETIMHAREKETI->Post();

        querySTOKLIST->Close();
        querySQL->Next();
    }
    tblURETIMHAREKETI->First();
    querySQL->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::StokMaliyetHesaplamasi(void)
{
    double nTutar = 0, nKDVTutari = 0;

    // �retim Re�etesindeki stok maliyetini hesaplayan kod....
    queryURETIMHAREKETI->SQL->Clear();
    queryURETIMHAREKETI->SQL->Add("SELECT * FROM URUNHAR");
    queryURETIMHAREKETI->ExecSQL();
    queryURETIMHAREKETI->Open();
    queryURETIMHAREKETI->First();
    while (!queryURETIMHAREKETI->Eof) {
        nTutar += queryURETIMHAREKETITUTAR->Value;
        nKDVTutari += queryURETIMHAREKETIKDVTUTARI->Value;
        queryURETIMHAREKETI->Next();
    }
    queryURETIMHAREKETI->Close();

    tblSTOKANA->Edit();
    tblSTOKANAMALIYETI->Value = nTutar;
    tblSTOKANAKDV_TUTARI->Value = nKDVTutari;
    // ��letme kar� hesaplan�yor...
    frmParametreler->tblPARAMETRE->Open();
    tblSTOKANA->Edit();
    tblSTOKANAISLETME_KARI->Value =  tblSTOKANAMALIYETI->Value /
            100 * frmParametreler->tblPARAMETREKAR_ORANI->Value;
    // ��letme gideri hesaplan�yor...
    tblSTOKANA->Edit();
    tblSTOKANAISLETME_GIDERI->Value = tblSTOKANAMALIYETI->Value /
            100 * frmParametreler->tblPARAMETREISLETME_ORANI->Value;
    frmParametreler->tblPARAMETRE->Close();
    // Ara Toplam bulunuyooor...
    tblSTOKANA->Edit();
    tblSTOKANAARA_TOPLAM->Value = tblSTOKANAMALIYETI->Value +
        tblSTOKANAISLETME_KARI->Value + tblSTOKANAISLETME_GIDERI->Value;
    // Genel Toplam Bulunuyor...
    tblSTOKANA->Edit();
    tblSTOKANAGENEL_TOPLAM->Value = tblSTOKANAARA_TOPLAM->Value
         + tblSTOKANAKDV_TUTARI->Value;
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbeditBirimFiyatiChange(TObject *Sender)
{
    if (tblSTOKANA->Active == true) {
        tblSTOKANA->Edit();
        tblSTOKANAYUVARLAMA->Value = tblSTOKANABIRIM_FIYATI->Value;
        if (dbeditBirimFiyati->Text.Length() == 0) {
            tblSTOKANA->Edit();
            tblSTOKANAYUVARLAMA->Value = 0;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::UretimAnaSil(void)
{
    // Onceki �retim ana dosyas�ndan A�A�IDAK� KODLA siliniyor....
    querySQL->Close();
    querySQL->SQL->Clear();
    querySQL->SQL->Add("DELETE FROM URUNANA");
    querySQL->SQL->Add("WHERE URUNKODU='"+tblSTOKANAINDEKS->Value+"'");
    querySQL->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::StokGecmisiSil(void)
{
    // Stok Kart� fiyat ge�mi�i A�A�IDAK� KODLA siliniyor...
    querySQL->Close();
    querySQL->SQL->Clear();
    querySQL->SQL->Add("DELETE FROM FIYATGECMISI");
    querySQL->SQL->Add("WHERE INDEKS='"+tblSTOKANAINDEKS->Value+"'");
    querySQL->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::UretimAnaOlustur(void)
{
    // Uretim hareketinden, �retim ana dosyas� olu�turuluyor...
    if (DBRadioGroup1->ItemIndex == 1) {
        tblURETIMHAREKETI->First();
        tblURETIMANA->Open();
        while (!tblURETIMHAREKETI->Eof) {
            tblURETIMANA->Insert();
            tblURETIMANA->Edit();
            tblURETIMANAURUNKODU->Value = tblSTOKANAINDEKS->Value;
            tblURETIMANA->Edit();
            tblURETIMANAMALZEMEKODU->Value =
                tblSTOKANADEPARTMAN->Value + FloatToStr(tblURETIMHAREKETIKOD->Value);
            tblURETIMANA->Edit();
            tblURETIMANAMALZEMEMIKTARI->Value = tblURETIMHAREKETIMIKTAR->Value;
            tblURETIMANA->Post();
            tblURETIMHAREKETI->Next();
        }
        tblURETIMANA->Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbeditYuvarlamaChange(TObject *Sender)
{
    if (tblSTOKANA->Active == true) {
        tblSTOKANA->Edit();
        tblSTOKANABIRIM_FIYATI->Value = tblSTOKANAYUVARLAMA->Value;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::UretimRecetesiSifirla(void)
{
    tblURETIMHAREKETI->Close();
    tblURETIMHAREKETI->EmptyTable();

    if (DBRadioGroup1->ItemIndex == 1)
        tblURETIMHAREKETI->Open();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbeditYuvarlamaKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::Kopyala1Click(TObject *Sender)
{
    frmKartKopyala->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::TopluMakiyetMuaddelBasm1Click(
      TObject *Sender)
{
    frmTopluRapor->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::TabloyuBoalt1Click(TObject *Sender)
{
    int nDeger;

    nDeger = Application->MessageBox("Tabloyu bo�altmak istedi�inize emin misiniz?", "Silme onay�",
        MB_YESNO + MB_ICONQUESTION);

    if (nDeger == IDYES)
        UretimRecetesiSifirla();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::tblSTOKANABIRIM_FIYATIChange(TField *Sender)
{
    TDateTime Zaman;

    tblSTOKANA->Edit();
    tblSTOKANATARIH->Value = Zaman.CurrentDate();
    tblSTOKANA->Edit();
    tblSTOKANASAAT->Value = Zaman.CurrentTime();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::StokDurumunuHesapla(void)
{
    double nGirisToplami = 0, nCikisToplami = 0;

    nGirisToplami = 0;
    querySTOKDURUMGIRISI->Open();
    querySTOKDURUMGIRISI->First();
    while (!querySTOKDURUMGIRISI->Eof) {
        nGirisToplami += querySTOKDURUMGIRISIMIKTAR->Value;
        querySTOKDURUMGIRISI->Next();
    }
    nCikisToplami = 0;
    querySTOKDURUMCIKISI->Open();
    querySTOKDURUMCIKISI->First();
    while (!querySTOKDURUMCIKISI->Eof) {
        nCikisToplami += querySTOKDURUMCIKISIMIKTAR->Value;
        querySTOKDURUMCIKISI->Next();
    }

    querySTOKDURUMCIKISI->First();
    querySTOKDURUMGIRISI->First();
    // Sadece malzeme i�in hesaplan�yor...
    if (DBRadioGroup1->ItemIndex == 0) {
        tblSTOKANA->Edit();
        tblSTOKANASON_DURUM->Value =
            (tblSTOKANADEVIR_MIKTARI->Value + nGirisToplami) - nCikisToplami;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::tblSTOKANADEVIR_MIKTARIChange(
      TField *Sender)
{
    StokDurumunuHesapla();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbcomboDepartmanChange(TObject *Sender)
{
    SpeedButton1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbcomboMuaddelBirimiKeyPress(
      TObject *Sender, char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbeditMuaddelBirimOraniKeyPress(
      TObject *Sender, char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::dbcomboMuaddelBirimiChange(TObject *Sender)
{
    frmOlcuBirimi->tblOLCU->Open();
    frmOlcuBirimi->tblOLCU->RecNo = dbcomboMuaddelBirimi->ItemIndex+1;
    tblSTOKANA->Edit();
    tblSTOKANAMUADDEL_BIRIM_ORANI->Value = frmOlcuBirimi->tblOLCUBIRIM_ORANI->Value;
    frmOlcuBirimi->tblOLCU->Close();    
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::FiyatGemiListesineEkle1Click(
      TObject *Sender)
{
    frmTarihSecimi->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::Sil3Click(TObject *Sender)
{
    int nDeger;

    nDeger = Application->MessageBox("Kayd� silmek istedi�inize emin misiniz?", "Silme onay�",
        MB_YESNO + MB_ICONQUESTION);

    if (nDeger == IDYES) {
        queryFIYATGECMISISIL->Close();
        queryFIYATGECMISISIL->SQL->Clear();
        queryFIYATGECMISISIL->SQL->Add("DELETE FROM FIYATGECMISI");
        queryFIYATGECMISISIL->SQL->Add("WHERE (TARIH='"+queryFIYATGECMISITARIH->Value.DateString()
            +"' AND FIYAT="+FloatToStr(queryFIYATGECMISIFIYAT->Value)+")");
        queryFIYATGECMISISIL->ExecSQL();
    }
    FiyatGecmisiGuncelle();
}
//---------------------------------------------------------------------------
void __fastcall TfrmStokKarti::Ekle1Click(TObject *Sender)
{
    frmTarihSecimi->Show();    
}
//---------------------------------------------------------------------------


void __fastcall TfrmStokKarti::comboCinsiChange(TObject *Sender)
{
    Animate1->Active = true;
    querySTOKLISTESI->Close();
    querySTOKLISTESI->ParamByName("DEPARTMAN")->AsString = dbcomboDepartman->Text;
    if (editKodaGore->Text.Length() != 0) {
        querySTOKLISTESI->ParamByName("KOD")->AsFloat = StrToFloat(editKodaGore->Text);
        querySTOKLISTESI->ParamByName("ADI")->AsString = NULL;
    }
    else {
        querySTOKLISTESI->ParamByName("KOD")->AsFloat = NULL;
        querySTOKLISTESI->ParamByName("ADI")->AsString = "%"+editAdaGore->Text+"%";
    }
    querySTOKLISTESI->ParamByName("CINSI")->AsString = "%"+comboCinsi->Text+"%";
    querySTOKLISTESI->Open();
    Animate1->Active = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmStokKarti::DBGrid4KeyPress(TObject *Sender, char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        DBGrid4DblClick(Sender);        
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::editAdaGoreClick(TObject *Sender)
{
    editAdaGore->Color = clWindow;
    editKodaGore->Color = clScrollBar;
    editKodaGore->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStokKarti::editKodaGoreClick(TObject *Sender)
{
    editKodaGore->Color = clWindow;
    editAdaGore->Color = clScrollBar;
    editAdaGore->Clear();
}
//---------------------------------------------------------------------------


