from ROOT import TF2, TCanvas, kBlue, kRed
#To run this macro just run on the terminal
#python2 twodfunction.py
c=TCanvas("c","Function",700,700)
c.Divide(2,1)
c.cd(1)
f1 =TF2("f2","sin(x)*sin(y)/(x*y)",0,5,0,5)
f1.SetLineColor(kRed)
f1.SetLineStyle(8)
f1.Draw()
c.cd(2)
f2 =TF2("f2", "cos(x)*sin(x*y)", 0., 5.,0.,5.)   
f2.SetLineColor(kBlue)
f2.SetLineStyle(9)
f2.Draw()
c.Draw()
c.SaveAs("twodhistopy.png")