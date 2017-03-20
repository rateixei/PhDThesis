{
//=========Macro generated from canvas: FakeRatio/FakeRatio
//=========  (Tue Nov 18 12:40:22 2014) by ROOT version5.34/18
   TCanvas *FakeRatio = new TCanvas("FakeRatio", "FakeRatio",233,93,900,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   FakeRatio->Range(16.6019,-0.625,142.6653,5.625);
   FakeRatio->SetFillColor(0);
   FakeRatio->SetBorderMode(0);
   FakeRatio->SetBorderSize(2);
   //FakeRatio->SetGridy();
   FakeRatio->SetTickx(1);
   FakeRatio->SetTicky(1);
   FakeRatio->SetFrameBorderMode(0);
   FakeRatio->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(7);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetMarkerStyle(20);
   gre->SetPoint(0,35.19,3.5393);
   gre->SetPointError(0,2.48,0.00392497);
   gre->SetPoint(1,44.3,2.77918);
   gre->SetPointError(1,2.839,0.00412854);
   gre->SetPoint(2,54.36,2.31509);
   gre->SetPointError(2,2.844,0.00491422);
   gre->SetPoint(3,64.43,2.1591);
   gre->SetPointError(3,2.861,0.00635772);
   gre->SetPoint(4,74.49,2.03282);
   gre->SetPointError(4,2.866,0.00806402);
   gre->SetPoint(5,88.3,1.9321);
   gre->SetPointError(5,5.64,0.00785714);
   gre->SetPoint(6,111.9,1.74032);
   gre->SetPointError(6,8.354,0.00991177);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,23.9556,129.0084);
   Graph_Graph1->SetMinimum(0);
   Graph_Graph1->SetMaximum(5);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);
   Graph_Graph1->GetXaxis()->SetTitle("Photon E_{T} [GeV]");
   Graph_Graph1->GetXaxis()->SetRange(6,101);
   //Graph_Graph1->GetYaxis()->SetTitle("Fake Ratio");
   Graph_Graph1->GetYaxis()->SetTitle("Extrapolation Factor");
   gre->SetHistogram(Graph_Graph1);
   
   
   TF1 *ffit0 = new TF1("ffit0","[0]+[1]/x^[2]",29.20824,130.0589);
   ffit0->SetFillColor(19);
   ffit0->SetFillStyle(0);
   ffit0->SetLineColor(40);
   ffit0->SetLineWidth(3);
   ffit0->SetChisquare(2.762415);
   ffit0->SetNDF(4);
   ffit0->SetParameter(0,1.503067);
   ffit0->SetParError(0,0.1086438);
   ffit0->SetParLimits(0,0,0);
   ffit0->SetParameter(1,981.0799);
   ffit0->SetParError(1,1069.642);
   ffit0->SetParLimits(1,0,0);
   ffit0->SetParameter(2,1.750146);
   ffit0->SetParError(2,0.3013514);
   ffit0->SetParLimits(2,0,0);
   gre->GetListOfFunctions()->Add(ffit0);
   
   TPaveStats *ptstats = new TPaveStats(0.605,0.58,0.81,0.75,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("#chi^{2} / ndf = 2.762 / 4");
   text = ptstats->AddText("Prob  = 0.5983");
   text = ptstats->AddText("p0       = 1.503 #pm 0.1086 ");
   text = ptstats->AddText("p1       = 981.1 #pm  1070 ");
   text = ptstats->AddText("p2       =  1.75 #pm 0.3014 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ap");
   
   TLegend *leg = new TLegend(0.61,0.75,0.80,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(42);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   //TLegendEntry *entry=leg->AddEntry("NULL","#splitline{#gamma Fake Ratio for QCD}{fit function: p0+p1/x^p2}","h");
   TLegendEntry *entry=leg->AddEntry("NULL","#splitline{#gamma Extr. Factor for QCD}{fit function: p0+p1/x^p2}","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   //entry->SetTextColor(40);
   entry->SetTextFont(42);
   leg->Draw();
   FakeRatio->Modified();
   FakeRatio->cd();
   FakeRatio->SetSelected(FakeRatio);
   
   
   TLatex *   tex = new TLatex(0.87,0.93,"7.3 fb^{-1} (8 TeV)");
   tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
   tex = new TLatex(0.22,0.8,"CMS");
   tex->SetNDC();
   tex->SetTextSize(0.0525);
   tex->SetLineWidth(2);
   tex->Draw();
   tex = new TLatex(0.2,0.75,"Preliminary");
   tex->SetNDC();
   tex->SetTextFont(52);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
   
   
}
