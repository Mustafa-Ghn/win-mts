//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "stokana.h"
#include "donemsonu.h"
#include "hareketraporu.h"
#include "hasilatraporu.h"
#include "anamenu.h"
#include "fiyatraporu.h"
#include "departman.h"
#include "uruncinsi.h"
#include "raporayar.h"
#include "muadraporu.h"
#include "sayimrap.h"
#include "stoklist.h"
#include "maliyet.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmRaporSecimi *frmRaporSecimi;

typedef struct _YETKILI {
    char Ad[50];
    char Rutbe[50];
    char Gorevi[100];
} YETKILI;

YETKILI Yetkili[5];

void __fastcall TfrmRaporSecimi::PersonelBilgisiDoldur(void)
{
    comboYETKILI1->Items->Clear();
    comboYETKILI2->Items->Clear();
    comboYETKILI3->Items->Clear();
    comboYETKILI4->Items->Clear();
    comboYETKILI5->Items->Clear();

    queryPERSONEL->Open();
    queryPERSONEL->First();
    while (!queryPERSONEL->Eof) {
        comboYETKILI1->Items->Add(queryPERSONELAdSoyad->Value);
        comboYETKILI2->Items->Add(queryPERSONELAdSoyad->Value);
        comboYETKILI3->Items->Add(queryPERSONELAdSoyad->Value);
        comboYETKILI4->Items->Add(queryPERSONELAdSoyad->Value);
        comboYETKILI5->Items->Add(queryPERSONELAdSoyad->Value);
        queryPERSONEL->Next();
    }
    queryPERSONEL->Close();
}

void __fastcall TfrmRaporSecimi::RutbeYukle(void)
{
    FILE *fpDosya;

    if ((fpDosya = fopen("YETKILI.DAT", "rb+")) == NULL) {
        Application->MessageBoxA("Dosya yarat�lam�yor! ! !. \nDiskinizde yer olmayabilir...",
            "Uyar� Mesaj�", MB_OK + MB_ICONEXCLAMATION);
    }
    else {
        fseek(fpDosya, 0, SEEK_SET);
        fread(&Yetkili, 5, sizeof(YETKILI), fpDosya);
    }
    fclose(fpDosya);
    comboYETKILI1->Text = AnsiString(Yetkili[0].Ad);
    editYETKILI1RUTBE->Text = AnsiString(Yetkili[0].Rutbe);
    editYETKILI1GOREVI->Text = AnsiString(Yetkili[0].Gorevi);
    comboYETKILI2->Text = AnsiString(Yetkili[1].Ad);
    editYETKILI2RUTBE->Text = AnsiString(Yetkili[1].Rutbe);
    editYETKILI2GOREVI->Text = AnsiString(Yetkili[1].Gorevi);
    comboYETKILI3->Text = AnsiString(Yetkili[2].Ad);
    editYETKILI3RUTBE->Text = AnsiString(Yetkili[2].Rutbe);
    editYETKILI3GOREVI->Text = AnsiString(Yetkili[2].Gorevi);
    comboYETKILI4->Text = AnsiString(Yetkili[3].Ad);
    editYETKILI4RUTBE->Text = AnsiString(Yetkili[3].Rutbe);
    editYETKILI4GOREVI->Text = AnsiString(Yetkili[3].Gorevi);
    comboYETKILI5->Text = AnsiString(Yetkili[4].Ad);
    editYETKILI5RUTBE->Text = AnsiString(Yetkili[4].Rutbe);
    editYETKILI5GOREVI->Text = AnsiString(Yetkili[4].Gorevi);
}

void __fastcall TfrmRaporSecimi::RutbeKaydet(void)
{
    FILE *fpDosya;

    memset(Yetkili, 0, 5*sizeof(YETKILI));
    strcpy(Yetkili[0].Ad, comboYETKILI1->Text.c_str());
    strcpy(Yetkili[0].Rutbe, editYETKILI1RUTBE->Text.c_str());
    strcpy(Yetkili[0].Gorevi, editYETKILI1GOREVI->Text.c_str());
    strcpy(Yetkili[1].Ad, comboYETKILI2->Text.c_str());
    strcpy(Yetkili[1].Rutbe, editYETKILI2RUTBE->Text.c_str());
    strcpy(Yetkili[1].Gorevi, editYETKILI2GOREVI->Text.c_str());
    strcpy(Yetkili[2].Ad, comboYETKILI3->Text.c_str());
    strcpy(Yetkili[2].Rutbe, editYETKILI3RUTBE->Text.c_str());
    strcpy(Yetkili[2].Gorevi, editYETKILI3GOREVI->Text.c_str());
    strcpy(Yetkili[3].Ad, comboYETKILI4->Text.c_str());
    strcpy(Yetkili[3].Rutbe, editYETKILI4RUTBE->Text.c_str());
    strcpy(Yetkili[3].Gorevi, editYETKILI4GOREVI->Text.c_str());
    strcpy(Yetkili[4].Ad, comboYETKILI5->Text.c_str());
    strcpy(Yetkili[4].Rutbe, editYETKILI5RUTBE->Text.c_str());
    strcpy(Yetkili[4].Gorevi, editYETKILI5GOREVI->Text.c_str());

    if ((fpDosya = fopen("YETKILI.DAT", "wb+")) == NULL) {
        Application->MessageBoxA("Dosya yarat�lam�yor! ! !. \nDiskinizde yer olmayabilir...",
            "Uyar� Mesaj�", MB_OK + MB_ICONEXCLAMATION);
    }
    else {
        fseek(fpDosya, 0, SEEK_SET);
        fwrite(&Yetkili, 5, sizeof(YETKILI), fpDosya);
    }
    fclose(fpDosya);
}
//---------------------------------------------------------------------------
__fastcall TfrmRaporSecimi::TfrmRaporSecimi(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmRaporSecimi::BitBtn2Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRaporSecimi::comboYETKILI1Change(TObject *Sender)
{
    queryPERSONEL->Open();
    queryPERSONEL->RecNo = comboYETKILI1->ItemIndex+1;
    editYETKILI1RUTBE->Text = queryPERSONELRutbe->Value;
    editYETKILI1GOREVI->Text = queryPERSONELGorevi->Value;
    queryPERSONEL->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRaporSecimi::comboYETKILI2Change(TObject *Sender)
{
    queryPERSONEL->Open();
    queryPERSONEL->RecNo = comboYETKILI2->ItemIndex+1;
    editYETKILI2RUTBE->Text = queryPERSONELRutbe->Value;
    editYETKILI2GOREVI->Text = queryPERSONELGorevi->Value;
    queryPERSONEL->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRaporSecimi::comboYETKILI3Change(TObject *Sender)
{
    queryPERSONEL->Open();
    queryPERSONEL->RecNo = comboYETKILI3->ItemIndex+1;
    editYETKILI3RUTBE->Text = queryPERSONELRutbe->Value;
    editYETKILI3GOREVI->Text = queryPERSONELGorevi->Value;
    queryPERSONEL->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRaporSecimi::comboYETKILI4Change(TObject *Sender)
{
    queryPERSONEL->Open();
    queryPERSONEL->RecNo = comboYETKILI4->ItemIndex+1;
    editYETKILI4RUTBE->Text = queryPERSONELRutbe->Value;
    editYETKILI4GOREVI->Text = queryPERSONELGorevi->Value;
    queryPERSONEL->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRaporSecimi::comboYETKILI5Change(TObject *Sender)
{
    queryPERSONEL->Open();
    queryPERSONEL->RecNo = comboYETKILI5->ItemIndex+1;
    editYETKILI5RUTBE->Text = queryPERSONELRutbe->Value;
    editYETKILI5GOREVI->Text = queryPERSONELGorevi->Value;
    queryPERSONEL->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRaporSecimi::FormShow(TObject *Sender)
{
    frmAnaMenu->Database->Connected = true;

    // Cinsi ComboBox'�na kay�t ekleniyor...
    comboStokCinsiBaslangic->Items->Clear();
    comboStokCinsiBitis->Items->Clear();
    frmUrunCinsi->tblURUNCINSI->Open();
    frmUrunCinsi->tblURUNCINSI->First();
    comboStokCinsiBaslangic->Items->Add("");
    comboStokCinsiBitis->Items->Add("");
    comboStokCinsiBaslangic->Items->Add("MALZEME");
    comboStokCinsiBitis->Items->Add("MALZEME");
    while (!frmUrunCinsi->tblURUNCINSI->Eof) {
        comboStokCinsiBaslangic->Items->Add(frmUrunCinsi->tblURUNCINSIURUNCINSI->Value);
        comboStokCinsiBitis->Items->Add(frmUrunCinsi->tblURUNCINSIURUNCINSI->Value);
        frmUrunCinsi->tblURUNCINSI->Next();
    }
    frmUrunCinsi->tblURUNCINSI->Close();

    // Departman ComboBox'�na kay�t ekleme toplu kodu
    comboDepartmanBaslangic->Items->Clear();
    comboDepartmanBitis->Items->Clear();
    frmDepartman->tblDEPARTMAN->Open();
    frmDepartman->tblDEPARTMAN->First();
    comboDepartmanBaslangic->Items->Add("");
    comboDepartmanBitis->Items->Add("");
    while (!frmDepartman->tblDEPARTMAN->Eof) {
        comboDepartmanBaslangic->Items->Add(frmDepartman->tblDEPARTMANDEPARTMAN->Value);
        comboDepartmanBitis->Items->Add(frmDepartman->tblDEPARTMANDEPARTMAN->Value);
        frmDepartman->tblDEPARTMAN->Next();
    }
    frmDepartman->tblDEPARTMAN->Close();
    // ---------------------------------- kod sonu...

    PersonelBilgisiDoldur();
    RutbeYukle();
    queryPERSONEL->Open();
    RadioGroup1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TfrmRaporSecimi::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    queryPERSONEL->Close();
    if (frmStokKarti->tblSTOKANA->Active == false)
        frmAnaMenu->Database->Connected = false;
    RutbeKaydet();
    speedbutonBITISClick(Sender);
    speedbutonBASLANGICClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TfrmRaporSecimi::RadioGroup1Click(TObject *Sender)
{
    speedbutonBASLANGICClick(Sender);
    speedbutonBITISClick(Sender);
    switch (RadioGroup1->ItemIndex) {
        case 0: // Maliyet Cetveli
        case 1: // Muaddel Cetveli
            checkboxGIRIS->Visible = false;
            checkboxCIKIS->Visible = false;
            checkboxHAZIRLIK->Visible = false;
            // Ba�lang�� Nesneleri
            SpeedButton1->Enabled = true;
            DateTimePicker2->Enabled = true;
            comboDepartmanBaslangic->Enabled = true;
            comboStokCinsiBaslangic->Enabled = true;
            editBaslangicStokKodu->Enabled = true;
            editBaslangicStokAdi->Enabled = true;
            // Biti� Nesneleri
            SpeedButton2->Enabled = false;
            DateTimePicker3->Enabled = false;
            comboDepartmanBitis->Enabled = false;
            comboStokCinsiBitis->Enabled = false;
            editBitisStokKodu->Enabled = false;
            editBitisStokAdi->Enabled = false;
            break;
        case 3: // Say�m Raporu
            checkboxGIRIS->Visible = false;
            checkboxCIKIS->Visible = false;
            checkboxHAZIRLIK->Visible = true;
            // Ba�lang�� Nesneleri
            SpeedButton1->Enabled = true;
            DateTimePicker2->Enabled = true;
            comboDepartmanBaslangic->Enabled = true;
            comboStokCinsiBaslangic->Enabled = true;
            editBaslangicStokKodu->Enabled = true;
            editBaslangicStokAdi->Enabled = true;
            // Biti� Nesneleri
            SpeedButton2->Enabled = true;
            DateTimePicker3->Enabled = true;
            comboDepartmanBitis->Enabled = true;
            comboStokCinsiBitis->Enabled = true;
            editBitisStokKodu->Enabled = true;
            editBitisStokAdi->Enabled = true;
            break;
        case 2: // Fiyat Listesi
        case 4: // Stok Kart Detay�
            checkboxGIRIS->Visible = false;
            checkboxCIKIS->Visible = false;
            checkboxHAZIRLIK->Visible = false;
            // Ba�lang�� Nesneleri
            SpeedButton1->Enabled = true;
            DateTimePicker2->Enabled = true;
            comboDepartmanBaslangic->Enabled = true;
            comboStokCinsiBaslangic->Enabled = true;
            editBaslangicStokKodu->Enabled = true;
            editBaslangicStokAdi->Enabled = true;
            // Biti� Nesneleri
            SpeedButton2->Enabled = true;
            DateTimePicker3->Enabled = false;
            comboDepartmanBitis->Enabled = true;
            comboStokCinsiBitis->Enabled = true;
            editBitisStokKodu->Enabled = true;
            editBitisStokAdi->Enabled = true;
            break;
        case 5: // G�nl�k Sat�� Cetveli
        case 6: // D�nem Sonu Raporu
            // E�er 5. RadioBox Se�ilmi�se checkbox'� i�levini kapa...
            if (RadioGroup1->ItemIndex == 5) {
                checkboxGIRIS->Visible = false;
                checkboxCIKIS->Visible = false;
            }
            else {
                checkboxGIRIS->Visible = true;
                checkboxCIKIS->Visible = true;
            }
            checkboxHAZIRLIK->Visible = false;
            checkboxGIRIS->Checked = true;
            checkboxCIKIS->Checked = true;
            // Ba�lang�� Nesneleri
            SpeedButton1->Enabled = false;
            DateTimePicker2->Enabled = true;
            comboDepartmanBaslangic->Enabled = true;
            comboStokCinsiBaslangic->Enabled = false;
            editBaslangicStokKodu->Enabled = false;
            editBaslangicStokAdi->Enabled = false;
            // Biti� Nesneleri
            SpeedButton2->Enabled = false;
            // E�er 5. RadioBox Se�ilmi�se tarih i�levini kapa...
            if (RadioGroup1->ItemIndex == 5)
                DateTimePicker3->Enabled = false;
            else
                DateTimePicker3->Enabled = true;
            // --------------------------- Sorgu Sonu
            comboDepartmanBitis->Enabled = false;
            comboStokCinsiBitis->Enabled = false;
            editBitisStokKodu->Enabled = false;
            editBitisStokAdi->Enabled = false;
            break;
    }
    speedbutonBASLANGIC->Enabled = SpeedButton1->Enabled;
    speedbutonBITIS->Enabled = SpeedButton2->Enabled;
}
//---------------------------------------------------------------------------
void __fastcall TfrmRaporSecimi::FiyatListesiRaporOncesiHazirlik(void)
{
    frmFiyatListesi->qrlabelISLETME_ADI->Caption = comboDepartmanBaslangic->Text;
    frmFiyatListesi->qrlabelTARIH->Caption = DateToStr(DateTimePicker2->Date);
    // �mza Bilgisi Geliyor....
    frmFiyatListesi->qrlabelYETKILI_ADI->Caption = comboYETKILI1->Text;
    frmFiyatListesi->qrlabelYETKILI_RUTBESI->Caption = editYETKILI1RUTBE->Text;
    frmFiyatListesi->qrlabelYETKILI_GOREVI->Caption = editYETKILI1GOREVI->Text;

    frmFiyatListesi->QRImage1->Picture->LoadFromFile(frmAnaMenu->Database->Directory + "LOGO.BMP");
    frmFiyatListesi->querySTOKLISTESI->Active = false;
    frmFiyatListesi->querySTOKLISTESI->ParamByName("BASLANGIC_KOD")->AsFloat =
        StrToFloat(editBaslangicStokKodu->Text);
    frmFiyatListesi->querySTOKLISTESI->ParamByName("BITIS_KOD")->AsFloat =
        StrToFloat(editBitisStokKodu->Text);
    frmFiyatListesi->querySTOKLISTESI->ParamByName("DEPARTMAN")->AsString =
        comboDepartmanBaslangic->Text;
    frmFiyatListesi->querySTOKLISTESI->ParamByName("CINSI")->AsString =
        "%"+comboStokCinsiBaslangic->Text+"%";
    frmFiyatListesi->querySTOKLISTESI->Active = true;
}

void __fastcall TfrmRaporSecimi::SayimRaporuOncesiHazirlik(void)
{
    frmSayimRaporu->qrlabelISLETMEADI->Caption = comboDepartmanBaslangic->Text;
    frmSayimRaporu->qrlabelTARIH->Caption = DateToStr(DateTimePicker2->Date);

    // Say�m Raporu querySTOKANA Sorgusu Aktif Ediliyor...
    frmSayimRaporu->querySTOKANA->Active = false;
    frmSayimRaporu->querySTOKANA->ParamByName("BASLANGIC_KOD")->AsFloat =
        StrToFloat(editBaslangicStokKodu->Text);
    frmSayimRaporu->querySTOKANA->ParamByName("BITIS_KOD")->AsFloat =
        StrToFloat(editBitisStokKodu->Text);
    frmSayimRaporu->querySTOKANA->ParamByName("DEPARTMAN")->AsString =
        comboDepartmanBaslangic->Text;
    frmSayimRaporu->querySTOKANA->ParamByName("CINSI")->AsString =
        "%"+comboStokCinsiBaslangic->Text+"%";
    frmSayimRaporu->querySTOKANA->Active = true;

    frmSayimRaporu->tblSTOKANA->Active = true;
    // Stok_Durumunu G�ncelleyen Kod Toplulu�u
    frmSayimRaporu->querySTOKANA->First();
    while (!frmSayimRaporu->querySTOKANA->Eof) {
        // Stok_Durumu Giri�i Listeleniyor...
        frmSayimRaporu->querySTOKDURUMGIRISI->Active = false;
        frmSayimRaporu->querySTOKDURUMGIRISI->ParamByName("DEPARTMAN")->AsString
            = frmSayimRaporu->querySTOKANADEPARTMAN->Value;
        frmSayimRaporu->querySTOKDURUMGIRISI->ParamByName("KOD")->AsFloat
            = frmSayimRaporu->querySTOKANAKOD->Value;
        frmSayimRaporu->querySTOKDURUMGIRISI->Active = true;

        // Stok_Durumu ��k��� Listeleniyor...
        frmSayimRaporu->querySTOKDURUMCIKISI->Active = false;
        frmSayimRaporu->querySTOKDURUMCIKISI->ParamByName("DEPARTMAN")->AsString
            = frmSayimRaporu->querySTOKANADEPARTMAN->Value;
        frmSayimRaporu->querySTOKDURUMCIKISI->ParamByName("KOD")->AsFloat
            = frmSayimRaporu->querySTOKANAKOD->Value;
        frmSayimRaporu->querySTOKDURUMCIKISI->Active = true;

        // Say�m Raporundaki tblSTOKANA tablosunda stok sondurumu ayarlan�yor...
        frmSayimRaporu->tblSTOKANA->Filter
            = "[INDEKS] = '"+frmSayimRaporu->querySTOKANAINDEKS->Value+"'";
        frmSayimRaporu->tblSTOKANA->Filtered = true;
        frmSayimRaporu->tblSTOKANA->Edit();
        frmSayimRaporu->tblSTOKANASON_DURUM->Value =
            (frmSayimRaporu->querySTOKANADEVIR_MIKTARI->Value +
            frmSayimRaporu->querySTOKDURUMGIRISISUMOFMIKTAR->Value) -
            frmSayimRaporu->querySTOKDURUMCIKISISUMOFMIKTAR->Value;
        frmSayimRaporu->tblSTOKANA->Post();
        frmSayimRaporu->querySTOKANA->Next();
    }
    frmSayimRaporu->querySTOKDURUMCIKISI->Active = false;
    frmSayimRaporu->querySTOKDURUMGIRISI->Active = false;
    frmSayimRaporu->tblSTOKANA->Active = false;
    // ------------------------------------------------- Kod Toplulu�u Sonu...

    // Say�m Raporu querySTOKANA Sorgusu Aktif Ediliyor...
    frmSayimRaporu->querySTOKANA->Active = false;
    frmSayimRaporu->querySTOKANA->ParamByName("BASLANGIC_KOD")->AsFloat =
        StrToFloat(editBaslangicStokKodu->Text);
    frmSayimRaporu->querySTOKANA->ParamByName("BITIS_KOD")->AsFloat =
        StrToFloat(editBitisStokKodu->Text);
    frmSayimRaporu->querySTOKANA->ParamByName("DEPARTMAN")->AsString =
        comboDepartmanBaslangic->Text;
    frmSayimRaporu->querySTOKANA->Active = true;


    if (checkboxHAZIRLIK->Checked == true) {
        frmSayimRaporu->qrdbtextSON_DURUM->Enabled = false;
        frmSayimRaporu->qrexprTUTAR->Enabled = false;
        frmSayimRaporu->qrexprTUTAR_TOPLAMI->Enabled = false;
        frmSayimRaporu->qrexprONCEKI_SAYFA_TUTARI->Enabled = false;
    }
    else {
        frmSayimRaporu->qrdbtextSON_DURUM->Enabled = true;
        frmSayimRaporu->qrexprTUTAR->Enabled = true;
        frmSayimRaporu->qrexprTUTAR_TOPLAMI->Enabled = true;
        frmSayimRaporu->qrexprONCEKI_SAYFA_TUTARI->Enabled = true;
    }
}

void __fastcall TfrmRaporSecimi::MaliyetRaporOncesiHazirlik(void)
{
    // Maliyet Cetveli i�in �retim re�etesi olu�turulur...
    frmStokKarti->UretimRecetesiSifirla();
    frmStokKarti->UretimRecetesiOlustur(comboDepartmanBaslangic->Text+editBaslangicStokKodu->Text);

    // Maliyet Cetveli i�in paraflar atan�yor...
    frmMaliyetCetveli->qrlabelYETKILI1ADI->Caption = comboYETKILI1->Text;
    frmMaliyetCetveli->qrlabelYETKILI1RUTBE->Caption = editYETKILI1RUTBE->Text;
    frmMaliyetCetveli->qrlabelYETKILI1GOREVI->Caption = editYETKILI1GOREVI->Text;

    frmMaliyetCetveli->qrlabelYETKILI2ADI->Caption = comboYETKILI2->Text;
    frmMaliyetCetveli->qrlabelYETKILI2RUTBE->Caption = editYETKILI2RUTBE->Text;
    frmMaliyetCetveli->qrlabelYETKILI2GOREVI->Caption = editYETKILI2GOREVI->Text;

    frmMaliyetCetveli->qrlabelYETKILI3ADI->Caption = comboYETKILI3->Text;
    frmMaliyetCetveli->qrlabelYETKILI3RUTBE->Caption = editYETKILI3RUTBE->Text;
    frmMaliyetCetveli->qrlabelYETKILI3GOREVI->Caption = editYETKILI3GOREVI->Text;

    frmMaliyetCetveli->qrlabelYETKILI4ADI->Caption = comboYETKILI4->Text;
    frmMaliyetCetveli->qrlabelYETKILI4RUTBE->Caption = editYETKILI4RUTBE->Text;
    frmMaliyetCetveli->qrlabelYETKILI4GOREVI->Caption = editYETKILI4GOREVI->Text;

    frmMaliyetCetveli->qrlabelYETKILI5ADI->Caption = comboYETKILI5->Text;
    frmMaliyetCetveli->qrlabelYETKILI5RUTBE->Caption = editYETKILI5RUTBE->Text;
    frmMaliyetCetveli->qrlabelYETKILI5GOREVI->Caption = editYETKILI5GOREVI->Text;

    // ��letme Ad� tan�mlan�yor.....
    frmMaliyetCetveli->qrlabelISLETME_ADI->Caption = comboDepartmanBaslangic->Text;
    // Ka� kopya al�naca�� ayarlan�yor . . .
    frmMaliyetCetveli->QuickRep1->PrinterSettings->Copies
        = StrToFloat(editKopyaSayisi->Text);
    // Rapor tarihi atan�yor . . .
    frmMaliyetCetveli->qrlabelTARIH->Caption = DateToStr(DateTimePicker2->Date);
    frmMaliyetCetveli->queryURETIMRECETESI->Close();
    frmMaliyetCetveli->tblSTOKKARTI->Close();
    frmMaliyetCetveli->tblSTOKKARTI->Filtered = true;
    frmMaliyetCetveli->tblSTOKKARTI->Filter = "[INDEKS] = '"
        + comboDepartmanBaslangic->Text + editBaslangicStokKodu->Text + "'";
    frmMaliyetCetveli->tblSTOKKARTI->Open();
    frmMaliyetCetveli->queryURETIMRECETESI->Open();
}

void __fastcall TfrmRaporSecimi::GunlukSatisRaporuOncesiHazirlik(void)
{
    // G�nl�k Sat�� Cetveli i�in paraflar atan�yor...
    frmGunlukSatisCizelgesi->qrlabelYETKILI1ADI->Caption = comboYETKILI1->Text;
    frmGunlukSatisCizelgesi->qrlabelYETKILI1RUTBE->Caption = editYETKILI1RUTBE->Text;
    frmGunlukSatisCizelgesi->qrlabelYETKILI1GOREVI->Caption = editYETKILI1GOREVI->Text;

    frmGunlukSatisCizelgesi->qrlabelYETKILI2ADI->Caption = comboYETKILI2->Text;
    frmGunlukSatisCizelgesi->qrlabelYETKILI2RUTBE->Caption = editYETKILI2RUTBE->Text;
    frmGunlukSatisCizelgesi->qrlabelYETKILI2GOREVI->Caption = editYETKILI2GOREVI->Text;

    frmGunlukSatisCizelgesi->qrlabelYETKILI3ADI->Caption = comboYETKILI3->Text;
    frmGunlukSatisCizelgesi->qrlabelYETKILI3RUTBE->Caption = editYETKILI3RUTBE->Text;
    frmGunlukSatisCizelgesi->qrlabelYETKILI3GOREVI->Caption = editYETKILI3GOREVI->Text;

    frmGunlukSatisCizelgesi->qrlabelYETKILI4ADI->Caption = comboYETKILI4->Text;
    frmGunlukSatisCizelgesi->qrlabelYETKILI4RUTBE->Caption = editYETKILI4RUTBE->Text;
    frmGunlukSatisCizelgesi->qrlabelYETKILI4GOREVI->Caption = editYETKILI4GOREVI->Text;

    frmGunlukSatisCizelgesi->qrlabelYETKILI5ADI->Caption = comboYETKILI5->Text;
    frmGunlukSatisCizelgesi->qrlabelYETKILI5RUTBE->Caption = editYETKILI5RUTBE->Text;
    frmGunlukSatisCizelgesi->qrlabelYETKILI5GOREVI->Caption = editYETKILI5GOREVI->Text;

    // ��letme Ad� tan�mlan�yor.....
    frmGunlukSatisCizelgesi->qrlabelISLETME_ADI->Caption = comboDepartmanBaslangic->Text
     + " G�NL�K SATI� L�STES�";
    // Ka� kopya al�naca�� ayarlan�yor . . .
    frmGunlukSatisCizelgesi->QuickRep1->PrinterSettings->Copies
        = StrToFloat(editKopyaSayisi->Text);
    // Rapor tarihi atan�yor . . .
    frmGunlukSatisCizelgesi->qrlabelTARIH->Caption = DateToStr(DateTimePicker2->Date);

    // tblSATIS_CETVELI Table Burada filtreleniyor...
    frmGunlukSatisCizelgesi->tblSATIS_CETVELI->Active = false;
    frmGunlukSatisCizelgesi->tblSATIS_CETVELI->Filtered = true;
    frmGunlukSatisCizelgesi->tblSATIS_CETVELI->Filter = "[TARIH] = "+DateTimePicker2->DateTime.DateString()
        +" AND "+"[DEPARTMAN] = '"+comboDepartmanBaslangic->Text+"'";
    frmGunlukSatisCizelgesi->tblSATIS_CETVELI->Active = true;
}

void __fastcall TfrmRaporSecimi::HareketRaporuOncesiHazirlik(void)
{
    frmHareketRaporu->querySTOKANA->Active = false;
    frmHareketRaporu->querySTOKANA->ParamByName("DEPARTMAN")->AsString = comboDepartmanBaslangic->Text;
    frmHareketRaporu->querySTOKANA->ParamByName("CINSI")->AsString = "%"+comboStokCinsiBaslangic->Text+"%";
    frmHareketRaporu->querySTOKANA->ParamByName("BASLANGICKODU")->AsFloat = StrToFloat(editBaslangicStokKodu->Text);
    frmHareketRaporu->querySTOKANA->ParamByName("BITISKODU")->AsFloat = StrToFloat(editBitisStokKodu->Text);
    frmHareketRaporu->querySTOKANA->Active = true;

    frmHareketRaporu->querySTOKDURUMU->Active = false;
    frmHareketRaporu->querySTOKDURUMU->Active = true;

    frmHareketRaporu->qrlabelDEPARTMAN->Caption = comboDepartmanBaslangic->Text;
}

void __fastcall TfrmRaporSecimi::MuaddelRaporOncesiHazirlik(void)
{
    // Muaddel Cetveli i�in �retim re�etesi olu�turulur...
    frmStokKarti->UretimRecetesiSifirla();
    frmStokKarti->UretimRecetesiOlustur(comboDepartmanBaslangic->Text+editBaslangicStokKodu->Text);

    // Muaddel Cetveli i�in paraflar atan�yor...
    frmMuaddelCetveli->qrlabelYETKILI1ADI->Caption = comboYETKILI1->Text;
    frmMuaddelCetveli->qrlabelYETKILI1RUTBE->Caption = editYETKILI1RUTBE->Text;
    frmMuaddelCetveli->qrlabelYETKILI1GOREVI->Caption = editYETKILI1GOREVI->Text;

    frmMuaddelCetveli->qrlabelYETKILI2ADI->Caption = comboYETKILI2->Text;
    frmMuaddelCetveli->qrlabelYETKILI2RUTBE->Caption = editYETKILI2RUTBE->Text;
    frmMuaddelCetveli->qrlabelYETKILI2GOREVI->Caption = editYETKILI2GOREVI->Text;

    frmMuaddelCetveli->qrlabelYETKILI3ADI->Caption = comboYETKILI3->Text;
    frmMuaddelCetveli->qrlabelYETKILI3RUTBE->Caption = editYETKILI3RUTBE->Text;
    frmMuaddelCetveli->qrlabelYETKILI3GOREVI->Caption = editYETKILI3GOREVI->Text;

    frmMuaddelCetveli->qrlabelYETKILI4ADI->Caption = comboYETKILI4->Text;
    frmMuaddelCetveli->qrlabelYETKILI4RUTBE->Caption = editYETKILI4RUTBE->Text;
    frmMuaddelCetveli->qrlabelYETKILI4GOREVI->Caption = editYETKILI4GOREVI->Text;

    frmMuaddelCetveli->qrlabelYETKILI5ADI->Caption = comboYETKILI5->Text;
    frmMuaddelCetveli->qrlabelYETKILI5RUTBE->Caption = editYETKILI5RUTBE->Text;
    frmMuaddelCetveli->qrlabelYETKILI5GOREVI->Caption = editYETKILI5GOREVI->Text;

    // ��letme Ad� tan�mlan�yor.....
    frmMuaddelCetveli->qrlabelISLETME_ADI->Caption = comboDepartmanBaslangic->Text;

    // Ka� kopya al�naca�� ayarlan�yor . . .
    frmMuaddelCetveli->QuickRep1->PrinterSettings->Copies
        = StrToFloat(editKopyaSayisi->Text);
    // Rapor tarihi atan�yor . . .
    frmMuaddelCetveli->qrlabelTARIH->Caption = DateToStr(DateTimePicker2->Date);
    frmMuaddelCetveli->queryURETIMRECETESI->Close();
    frmMuaddelCetveli->tblSTOKKARTI->Close();
    frmMuaddelCetveli->tblSTOKKARTI->Filtered = true;
    frmMuaddelCetveli->tblSTOKKARTI->Filter = "[INDEKS] = '"
        + comboDepartmanBaslangic->Text + editBaslangicStokKodu->Text + "'";
    frmMuaddelCetveli->tblSTOKKARTI->Open();
    frmMuaddelCetveli->queryURETIMRECETESI->Open();
}

void __fastcall TfrmRaporSecimi::DonemSonuRaporuOncesiHazirlik(void)
{
    frmDonemSonu->qrlabelUNITE->Caption = comboDepartmanBaslangic->Text;
    frmDonemSonu->qrlabelTARIH->Caption = DateTimePicker2->DateTime.DateString()
        + " - " + DateTimePicker3->DateTime.DateString() + " Tarihleri Aras�";
    frmDonemSonu->queryDONEMSONU->Close();
    frmDonemSonu->queryDONEMSONU->ParamByName("DEPARTMAN")->AsString = comboDepartmanBaslangic->Text;
    frmDonemSonu->queryDONEMSONU->ParamByName("BASTARIHI")->AsDate = DateTimePicker2->Date;
    frmDonemSonu->queryDONEMSONU->ParamByName("BITTARIHI")->AsDate = DateTimePicker3->Date;
    frmDonemSonu->queryDONEMSONU->ParamByName("GIRIS")->AsBoolean = checkboxGIRIS->Checked;
    frmDonemSonu->queryDONEMSONU->ParamByName("CIKIS")->AsBoolean = !(checkboxCIKIS->Checked);
    frmDonemSonu->queryDONEMSONU->Open();
}

void __fastcall TfrmRaporSecimi::BitBtn1Click(TObject *Sender)
{
    switch (RadioGroup1->ItemIndex) {
        case 0:
            MaliyetRaporOncesiHazirlik();
            frmMaliyetCetveli->QuickRep1->Preview();
            break;
        case 1:
            MuaddelRaporOncesiHazirlik();
            frmMuaddelCetveli->QuickRep1->Preview();
            break;
        case 2:
            FiyatListesiRaporOncesiHazirlik();
            frmFiyatListesi->QuickRep1->Preview();
            break;
        case 3:
            SayimRaporuOncesiHazirlik();
            frmSayimRaporu->QuickRep1->Preview();
            break;
        case 4:
            HareketRaporuOncesiHazirlik();
            frmHareketRaporu->QuickRep1->Preview();
            break;
        case 5:
            GunlukSatisRaporuOncesiHazirlik();
            frmGunlukSatisCizelgesi->QuickRep1->Preview();
            break;
        case 6:
            DonemSonuRaporuOncesiHazirlik();
            frmDonemSonu->QuickRep1->Preview();
            break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmRaporSecimi::SpeedButton1Click(TObject *Sender)
{
    frmStokListesi->Caption = "Stok Listesi [Rapor Se�imi - Ba�lang��]";
    frmStokListesi->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRaporSecimi::SpeedButton2Click(TObject *Sender)
{
    frmStokListesi->Caption = "Stok Listesi [Rapor Se�imi - Biti�]";
    frmStokListesi->Show();
}
//---------------------------------------------------------------------------


void __fastcall TfrmRaporSecimi::speedbutonBASLANGICClick(TObject *Sender)
{
    DateTimePicker2->Date = DateTimePicker2->DateTime.CurrentDate();
    comboDepartmanBaslangic->ItemIndex = 0;
    comboStokCinsiBaslangic->ItemIndex = 0;
    editBaslangicStokKodu->Clear();
    editBaslangicStokAdi->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRaporSecimi::speedbutonBITISClick(TObject *Sender)
{
    DateTimePicker3->Date = DateTimePicker3->DateTime.CurrentDate();
    comboDepartmanBitis->ItemIndex = 0;
    comboStokCinsiBitis->ItemIndex = 0;
    editBitisStokKodu->Clear();
    editBitisStokAdi->Clear();
}
//---------------------------------------------------------------------------
