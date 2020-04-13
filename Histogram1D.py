from ROOT import TH1F, TCanvas, kBlue, kRed, TAxis, gStyle, TLegend, TLatex, TFile, TRandom3
#To run this macro just run on the terminal
#python2 Histogram1D.py
c=TCanvas("c","Function",600,600)
h1=TH1F("1-D Histo","Histogram-1D",30,-3,3)
random=TRandom3()
for i in range(10000):
    value=random.Gaus(0.0,1.0)
    h1.Fill(value)
h1.SetLineColor(kBlue)
h1.SetLineStyle(1)
h1.SetFillColor(kRed)
h1.GetXaxis().SetTitle("1-D Histo")
h1.GetXaxis().CenterTitle()
h1.GetYaxis().SetTitle("Number of Entries")
h1.GetYaxis().CenterTitle()
h1.Draw()
c.SaveAs("oneDHistopy.png")
file= TFile("oneDHistopy.root","RECREATE")
h1.Write()
file.Close()