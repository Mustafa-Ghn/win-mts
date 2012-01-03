//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fiyatlandirma.h"
#include "departman.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmFiyatAyarlama *frmFiyatAyarlama;
//---------------------------------------------------------------------------
__fastcall TfrmFiyatAyarlama::TfrmFiyatAyarlama(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmFiyatAyarlama::LIFOyaGoreFiyatlandir(void)
{
    int nSayac = 0;

    SpeedButton1->Enabled = false;
    Animate1->Active = true;

    querySTOKANA->ParamByName("DEPARTMAN")->AsString = comboDepartman->Text+"%";
    querySTOKANA->Active = true;
    tblSTOKANA->Active = true;

    querySTOKANA->First();
    while (!querySTOKANA->Eof) {
        tblSTOKANA->Filtered = false;
        tblSTOKANA->Filter = "[INDEKS] = '"+querySTOKANAINDEKS->Value+"'";
        tblSTOKANA->Filtered = true;
        // �lerleme G�stergesi Hareketini Sa�layan Kod Toplulu�u
        nSayac = (100 * querySTOKANA->RecNo) / querySTOKANA->RecordCount;
        ProgressBar1->Position = nSayac;
        labelYUZDE->Caption = "% "+IntToStr(nSayac)+ " tamamland�.";
        labelYUZDE->Refresh();
        labelYUZDE->Caption = "% 0";
        editStokKodu->Text = querySTOKANADEPARTMAN->Value + " - "
            + FloatToStr(querySTOKANAKOD->Value);
        editStokKodu->Refresh();
        editStokKodu->Clear();
        editStokAdi->Text = querySTOKANAADI->Value;
        editStokAdi->Refresh();
        editStokAdi->Clear();
        // -------------------------------------- Kod Toplulu�u Sonu

        // �u an aktif olan stok kodunun hareketlerini listeleyen Kod Toplulu�u
        querySTOKGIRISI->Active = false;
        querySTOKGIRISI->ParamByName("DEPARTMAN")->AsString = querySTOKANADEPARTMAN->Value;
        querySTOKGIRISI->ParamByName("KOD")->AsFloat = querySTOKANAKOD->Value;
        querySTOKGIRISI->Active = true;

        // A�a��daki Kod Toplulu�u'nda - Giri� Miktar� - en son tarihli
        // hareketin birim fiyat� StokAna'n�n birim fiyat�na atan�yor....
        querySTOKGIRISI->Last();
        if (querySTOKGIRISI->RecordCount > 0) {
            tblSTOKANA->Edit();
            tblSTOKANABIRIM_FIYATI->Value = querySTOKGIRISIBIRIMFIYATI->Value;
            tblSTOKANA->Post();
        }
        // ----------------------------------------------- Kod Toplulu�u Sonu
        querySTOKANA->Next();
    }

    tblSTOKANA->Active = false;
    querySTOKANA->Active = false;
    querySTOKCIKISI->Active = false;
    querySTOKGIRISI->Active = false;

    ProgressBar1->Position = 0;
    Animate1->Active = false;
    SpeedButton1->Enabled = true;
}

void __fastcall TfrmFiyatAyarlama::FIFOyaGoreFiyatlandir(void)
{
    int nSayac = 0;
    double nGirisToplami = 0;

    SpeedButton1->Enabled = false;
    Animate1->Active = true;

    querySTOKANA->ParamByName("DEPARTMAN")->AsString = comboDepartman->Text+"%";
    querySTOKANA->Active = true;
    tblSTOKANA->Active = true;

    querySTOKANA->First();
    while (!querySTOKANA->Eof) {
        tblSTOKANA->Filtered = false;
        tblSTOKANA->Filter = "[INDEKS] = '"+querySTOKANAINDEKS->Value+"'";
        tblSTOKANA->Filtered = true;
        // �lerleme G�stergesi Hareketini Sa�layan Kod Toplulu�u
        nSayac = (100 * querySTOKANA->RecNo) / querySTOKANA->RecordCount;
        ProgressBar1->Position = nSayac;
        labelYUZDE->Caption = "% "+IntToStr(nSayac)+ " tamamland�.";
        labelYUZDE->Refresh();
        labelYUZDE->Caption = "% 0";
        editStokKodu->Text = querySTOKANADEPARTMAN->Value + " - "
            + FloatToStr(querySTOKANAKOD->Value);
        editStokKodu->Refresh();
        editStokKodu->Clear();
        editStokAdi->Text = querySTOKANAADI->Value;
        editStokAdi->Refresh();
        editStokAdi->Clear();
        // -------------------------------------- Kod Toplulu�u Sonu

        // �u an aktif olan stok kodunun hareketlerini listeleyen Kod Toplulu�u
        querySTOKGIRISI->Active = false;
        querySTOKGIRISI->ParamByName("DEPARTMAN")->AsString = querySTOKANADEPARTMAN->Value;
        querySTOKGIRISI->ParamByName("KOD")->AsFloat = querySTOKANAKOD->Value;
        querySTOKGIRISI->Active = true;

        querySTOKCIKISI->Active = false;
        querySTOKCIKISI->ParamByName("DEPARTMAN")->AsString = querySTOKANADEPARTMAN->Value;
        querySTOKCIKISI->ParamByName("KOD")->AsFloat = querySTOKANAKOD->Value;
        querySTOKCIKISI->Active = true;
        // ------------------------------------------- Kod Toplulu�u Sonu
        nGirisToplami = querySTOKANADEVIR_MIKTARI->Value;

        // A�a��daki Kod Toplulu�u'nda Giri� Miktar�, ��k�� Miktar�ndan k���k
        // oluncaya kadar d�ng�ye devam ediliyor. Ve B�y�k yada E�it oldu�unda ise
        // Birim Fiyat� StokAna'n�n birim fiyat�na atan�yor....
        querySTOKGIRISI->First();
        while (!querySTOKGIRISI->Eof && (nGirisToplami <= querySTOKCIKISISUMOFMIKTAR->Value)) {
            tblSTOKANA->Edit();
            tblSTOKANABIRIM_FIYATI->Value = querySTOKGIRISIBIRIMFIYATI->Value;
            tblSTOKANA->Post();

            nGirisToplami += querySTOKGIRISIMIKTAR->Value;
            querySTOKGIRISI->Next();
        }
        // ----------------------------------------------- Kod Toplulu�u Sonu
        querySTOKANA->Next();
    }

    tblSTOKANA->Active = false;
    querySTOKANA->Active = false;
    querySTOKCIKISI->Active = false;
    querySTOKGIRISI->Active = false;

    ProgressBar1->Position = 0;
    Animate1->Active = false;
    SpeedButton1->Enabled = true;
}

void __fastcall TfrmFiyatAyarlama::FiyatlandirmayiBaslat(void)
{
    if (RadioGroup1->ItemIndex == 0)
        FIFOyaGoreFiyatlandir();
    else
        LIFOyaGoreFiyatlandir();
}

void __fastcall TfrmFiyatAyarlama::SpeedButton1Click(TObject *Sender)
{
    int nDeger;

    nDeger = Application->MessageBox("Fiyatland�rmaya ba�lamak istedi�inize emin misiniz?", "Ba�latma Onay�",
        MB_YESNO + MB_ICONQUESTION);

    if (nDeger == IDYES) 
        FiyatlandirmayiBaslat();
}
//---------------------------------------------------------------------------
void __fastcall TfrmFiyatAyarlama::FormShow(TObject *Sender)
{
    // Departman ComboBox'�na kay�t ekleniyor...
    comboDepartman->Items->Clear();
    frmDepartman->tblDEPARTMAN->Open();
    frmDepartman->tblDEPARTMAN->First();
    comboDepartman->Items->Add("");
    while (!frmDepartman->tblDEPARTMAN->Eof) {
        comboDepartman->Items->Add(frmDepartman->tblDEPARTMANDEPARTMAN->Value);
        frmDepartman->tblDEPARTMAN->Next();
    }
    frmDepartman->tblDEPARTMAN->Close();

    comboDepartman->ItemIndex = 1;
}
//---------------------------------------------------------------------------
