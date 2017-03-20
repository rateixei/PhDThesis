void plot2dpretty() {

    gStyle->SetOptStat(0);
    //TFile* f1 = new TFile("2DLimitPlot_expected_met65to1000_mt0to1000.root","READ");
    TFile* f1 = new TFile("2DLimitPlot_expected_met65to1000_mt0to1000.root","READ");
    f1->cd();
    f1->ls();
    c_exp->SetLogz();
    c_exp->Draw();
    
    TH2F* expected2D = (TH2F*)c_exp->GetPrimitive("expected2D");
    TH2F* expected2Dclone = (TH2F*)expected2D->Clone("expected2Dclone");

    double conts[] = {10,50,100}; 
    expected2D->SetContour(3,conts);
    expected2D->Draw("contlistsame");
    c_exp->Update();
    TObjArray *contours = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
    

    const Int_t Number = 5;
    //Double_t Red[Number]    = { 1.0, 1.0, 1.0, 1.0, 1.0};
    //Double_t Green[Number]  = { 0.8, 0.6, 0.4, 0.2, 0.0};
    //Double_t Blue[Number]   = { 0.0, 0.0, 0.0, 0.0, 0.0};
    //Double_t Length[Number] = { 0.0, 0.2, 0.50, 0.7, 1.00 };

    Double_t Red[Number]    = { 1.0, 1.0, 1.0, 1.0, 1.0};
    Double_t Green[Number]  = { 1.0, 1.0, 0.8, 0.4, 0.0};
    Double_t Blue[Number]   = { 1.0, 0.4, 0.0, 0.0, 0.0};
    Double_t Length[Number] = { 0.0, 0.2, 0.50, 0.7, 1.00 };

    //Double_t Red[Number]    = { 1.0, 0.6, 0.4, 0.2, 0.0};
    //Double_t Green[Number]  = { 1.0, 0.6, 0.4, 0.2, 0.0};
    //Double_t Blue[Number]   = { 1.0, 1.0, 1.0, 1.0, 1.0};
    //Double_t Length[Number] = { 0.0, 0.2, 0.50, 0.7, 1.00 };
 
    Int_t nb=255;
    TColor::CreateGradientColorTable(Number,Length,Red,Green,Blue,nb);
    expected2D->SetContour(99);
    expected2D->GetZaxis()->SetTitle("#sigma_{exp} #times BR #times A #times #varepsilon [fb]");
    expected2D->GetXaxis()->SetTitle("#slashE_{T} Requirement");
    expected2D->GetYaxis()->SetTitle("M_{T} Requirement");
    expected2D->Draw("CONT4SAME");
    expected2D->SetTitle("");

    for (int ic=0; ic<contours->GetEntries(); ic++) {   
        std::cout<<"contour"<<ic<<std::endl;
        TList* graphlist = (TList*)contours->At(ic);   
        for (int ig=0; ig<graphlist->GetEntries(); ig++) {     
            TGraph* gr = (TGraph*)graphlist->At(ig);
            gr->Print();
            gr->SetLineWidth(6);
            gr->SetLineColor(1);
            gr->Draw("CSAME");
        }
    }

    c_exp->Update();
       
    TLatex *latex2 = new TLatex();
    latex2->SetNDC();
    latex2->SetTextSize(0.75*c_exp->GetTopMargin());
    latex2->SetTextFont(62);
    latex2->SetTextAlign(11);
    latex2->DrawLatex(0.22, 0.85, "CMS");
    latex2->SetTextSize(0.5*c_exp->GetTopMargin());
    latex2->SetTextFont(52);
    latex2->SetTextAlign(11);
    latex2->DrawLatex(0.20, 0.8, "Preliminary");



}
