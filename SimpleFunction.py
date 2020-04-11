from ROOT import TF1, TCanvas, kBlue, kRed
#To run this macro just write on the terminal
#python2 SimpleFunction.py
c=TCanvas("c","Function",700,700)

f1 = TF1("f1", "cos(x)", 0., 10.)
f2 =  TF1("f2", "sin(x)", 0., 10.)
f2.SetLineColor(kBlue)
f2.SetLineStyle(9)
f1.SetLineColor(kRed)
f1.SetLineStyle(8)
f1.Draw()
f2.Draw("Same")
c.Draw()
c.SaveAs("Functionpy.png")