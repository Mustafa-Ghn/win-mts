//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DepartmanDegis.h"
#include "departman.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmDepartmanAdiDegistir *frmDepartmanAdiDegistir;
//---------------------------------------------------------------------------
__fastcall TfrmDepartmanAdiDegistir::TfrmDepartmanAdiDegistir(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmDepartmanAdiDegistir::StokSatisCetveliDegistir(AnsiString EskiDepartman, AnsiString YeniDepartman)
{
    querySATISCETVELI->Active = false;
    querySATISCETVELI->SQL->Clear();
    querySATISCETVELI->SQL->Add("UPDATE SATISCETVELI");
    querySATISCETVELI->SQL->Add(" SET DEPARTMAN='"+YeniDepartman+"'");
    querySATISCETVELI->SQL->Add(" WHERE DEPARTMAN='"+EskiDepartman+"'");
    querySATISCETVELI->ExecSQL();
}
void __fastcall TfrmDepartmanAdiDegistir::StokHareketiDegistir(AnsiString EskiDepartman, AnsiString YeniDepartman)
{
    querySTOKHAR->Active = false;
    querySTOKHAR->SQL->Clear();
    querySTOKHAR->SQL->Add("UPDATE STOKHAR");
    querySTOKHAR->SQL->Add(" SET DEPARTMAN='"+YeniDepartman+"'");
    querySTOKHAR->SQL->Add(" WHERE DEPARTMAN='"+EskiDepartman+"'");
    querySTOKHAR->ExecSQL();
}

void __fastcall TfrmDepartmanAdiDegistir::StokDurumuDegistir(AnsiString EskiDepartman, AnsiString YeniDepartman)
{
    querySTOKDURUMU->Active = false;
    querySTOKDURUMU->SQL->Clear();
    querySTOKDURUMU->SQL->Add("UPDATE STOKDURUMU");
    querySTOKDURUMU->SQL->Add(" SET DEPARTMAN='"+YeniDepartman+"'");
    querySTOKDURUMU->SQL->Add(" WHERE DEPARTMAN='"+EskiDepartman+"'");
    querySTOKDURUMU->ExecSQL();
}

void __fastcall TfrmDepartmanAdiDegistir::FiyatGecmisiDegistir(AnsiString EskiIndeks, AnsiString YeniIndeks)
{
    queryFIYATGECMISI->Active = false;
    queryFIYATGECMISI->SQL->Clear();
    queryFIYATGECMISI->SQL->Add("UPDATE FIYATGECMISI");
    queryFIYATGECMISI->SQL->Add(" SET INDEKS='"+YeniIndeks+"'");
    queryFIYATGECMISI->SQL->Add(" WHERE INDEKS='"+EskiIndeks+"'");
    queryFIYATGECMISI->ExecSQL();
}

void __fastcall TfrmDepartmanAdiDegistir::UrunAnaDegistir(AnsiString EskiIndeks, AnsiString YeniIndeks)
{
    queryURUNANA->Active = false;
    queryURUNANA->SQL->Clear();
    queryURUNANA->SQL->Add("UPDATE URUNANA");
    queryURUNANA->SQL->Add("SET MALZEMEKODU='"+YeniIndeks+"'");
    queryURUNANA->SQL->Add("WHERE MALZEMEKODU='"+EskiIndeks+"'");
    queryURUNANA->ExecSQL();

    queryURUNANA->Active = false;
    queryURUNANA->SQL->Clear();
    queryURUNANA->SQL->Add("UPDATE URUNANA");
    queryURUNANA->SQL->Add("SET URUNKODU='"+YeniIndeks+"'");
    queryURUNANA->SQL->Add("WHERE URUNKODU='"+EskiIndeks+"'");
    queryURUNANA->ExecSQL();
}

void __fastcall TfrmDepartmanAdiDegistir::DegisiklikIsleminiUygula(void)
{
    float KalanKayitSayisi = 0;
    AnsiString EskiDepartman, YeniDepartman;
    AnsiString EskiIndeks, YeniIndeks;

    Animate1->Active = true;
    tblSTOKANA->Active = true;
    EskiDepartman = comboEskiDepartman->Text;
    YeniDepartman = editYeniDepartman->Text;

    querySTOKANA->Active = false;
    querySTOKANA->ParamByName("DEPARTMAN")->AsString = EskiDepartman;
    querySTOKANA->Active = true;
    querySTOKANA->First();
    // KalanKayit Say�s� ��reniliyor...
    KalanKayitSayisi = querySTOKANA->RecordCount;
    while (!querySTOKANA->Eof) {
        EskiIndeks = querySTOKANAINDEKS->Value;
        YeniIndeks = YeniDepartman + FloatToStr(querySTOKANAKOD->Value);
        // Kalan kay�t say�s� burada ekrana yazd�r�l�yor . . .
        --KalanKayitSayisi;
        StatusBar1->Panels->Items[1]->Text = FloatToStr(KalanKayitSayisi+1);

        // URUNANA.DB dosyas�n�n i�eri�i de�i�tiriliyor...
        UrunAnaDegistir(EskiIndeks, YeniIndeks);
        StatusBar1->Panels->Items[3]->Text = "�retim Re�etesi i�eri�i de�i�tiriliyor...";
        StatusBar1->Refresh();
        // FIYATGECMISI.DB dosyas�n�n i�eri�i de�i�tiriliyor...
        FiyatGecmisiDegistir(EskiIndeks, YeniIndeks);
        StatusBar1->Panels->Items[3]->Text = "Fiyat Ge�mi�i i�eri�i de�i�tiriliyor...";
        StatusBar1->Refresh();
        // STOKDURUMU.DB dosyas�n�n i�eri�i de�i�tiriliyor...
        StokDurumuDegistir(EskiDepartman, YeniDepartman);
        StatusBar1->Panels->Items[3]->Text = "Stok Durumu i�eri�i de�i�tiriliyor...";
        StatusBar1->Refresh();
        // STOKHAR.DB dosyas�n�n i�eri�i de�i�tiriliyor...
        StokHareketiDegistir(EskiDepartman, YeniDepartman);
        StatusBar1->Panels->Items[3]->Text = "Stok Hareketi i�eri�i de�i�tiriliyor...";
        StatusBar1->Refresh();
        // SATISCETVELI.DB dosyas�n�n i�eri�i de�i�tirliyor...
        StokSatisCetveliDegistir(EskiDepartman, YeniDepartman);
        StatusBar1->Panels->Items[3]->Text = "Sat�� Cetveli i�eri�i de�i�tiriliyor...";
        StatusBar1->Refresh();
        // STOKANA.DB dosyas�n�n i�eri�i de�i�tiriliyor.
        tblSTOKANA->Filtered = false;
        tblSTOKANA->Filter = "[INDEKS]='"+EskiIndeks+"'";
        tblSTOKANA->Filtered = true;
        tblSTOKANA->Edit();
        tblSTOKANAINDEKS->Value = YeniIndeks;
        tblSTOKANA->Edit();
        tblSTOKANADEPARTMAN->Value = YeniDepartman;
        tblSTOKANA->Post();
        StatusBar1->Panels->Items[3]->Text = "Stok Kart� i�eri�i de�i�tiriliyor...";
        StatusBar1->Refresh();
        querySTOKANA->Next();
    }
    // DEPARTMAN.DB dosyas�n�n i�eri�i de�i�tirliyor....
    tblDEPARTMAN->Active = true;
    tblDEPARTMAN->Filtered = false;
    tblDEPARTMAN->Filter = "[DEPARTMAN]='"+EskiDepartman+"'";
    tblDEPARTMAN->Filtered = true;
    tblDEPARTMAN->Edit();
    tblDEPARTMANDEPARTMAN->Value = YeniDepartman;
    tblDEPARTMAN->Post();
    tblDEPARTMAN->Active = false;
    StatusBar1->Panels->Items[3]->Text = "Departman dosyas�n�n i�eri�i de�i�tiriliyor...";

    querySTOKANA->Active = false;
    tblSTOKANA->Active = false;

    Animate1->Active = false;
    MessageBox(NULL, "��lem Tamamland�", "Bilgi Kutusu", MB_OK | MB_ICONINFORMATION);
    editYeniDepartman->Clear();
    StatusBar1->Panels->Items[3]->Text = "";
}

void __fastcall TfrmDepartmanAdiDegistir::SpeedButton1Click(
      TObject *Sender)
{
    int nDeger;

    if (editYeniDepartman->Text.Length() == 0)
        Application->MessageBoxA("Yeni Departman ad�n� girmeden i�lem yapamazs�n�z",
            "Uyar� Mesaj�", MB_OK + MB_ICONEXCLAMATION);
    else {
        nDeger = Application->MessageBox("Devam etmek istedi�inize emin misiniz?", "Kay�t Onay�",
            MB_YESNO + MB_ICONQUESTION);

        if (nDeger == IDYES)
            DegisiklikIsleminiUygula();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmDepartmanAdiDegistir::FormShow(TObject *Sender)
{
    // Departman ComboBox'�na kay�t ekleniyor...
    comboEskiDepartman->Items->Clear();
    frmDepartman->tblDEPARTMAN->Open();
    frmDepartman->tblDEPARTMAN->First();
    while (!frmDepartman->tblDEPARTMAN->Eof) {
        comboEskiDepartman->Items->Add(frmDepartman->tblDEPARTMANDEPARTMAN->Value);
        frmDepartman->tblDEPARTMAN->Next();
    }
    frmDepartman->tblDEPARTMAN->Close();

    comboEskiDepartman->ItemIndex = 0;
}
//---------------------------------------------------------------------------

