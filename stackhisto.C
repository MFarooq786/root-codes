void stackhisto()
{
            // To run this macro just run on root terminal 
    // .L stackhisto.C
    //First You have to download the root files in your working directory
    

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //   https://indico.cern.ch/event/607726/contributions/2475151/attachments/1496594/2328917/Signal_1fb.root  
  //  https://indico.cern.ch/event/607726/contributions/2475151/attachments/1496594/2328915/Background_1fb.root
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //I have take these root files from the HASCO Summer school 2017
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //                           https://indico.cern.ch/event/607726/                                                // 
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Here, We have read the Tree
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //          Author: Muhammad Farooq Email: 2714befarooq@gmail.com 
    //          muhammad.farooq@cern.ch
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //                           https://root.cern.ch/root-user-guides-and-manuals                                  // 
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //                           https://root.cern.ch/doc/master/classTCanvas.html                                  // 
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //                             TCanvas(name,title,width,height)                                                 // 
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //                             Define a Canvas                                                                // 
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas* c=new TCanvas("c","Tree",600,600);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //                           https://root.cern.ch/doc/v608/classTFile.html                                 // 
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //Now, we read the tree which are saved in .root file
  //here, we have open the file Signal_1fb.root, you can see the contenets type on the root terminal new TBrowser and press Enter
  //This will open a window now, click on the file Signal_1fb.root when you open this file, 
  //There, will be a Tree name tree, now click on the tree in this tree there will be two branches name
  //eventWeight and invariantMass that are two branches 
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //                             Set as Signal                                                                   // 
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TFile* Signal_file=new TFile("Signal_1fb.root","READ");
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //   https://indico.cern.ch/event/607726/contributions/2475151/attachments/1496594/2328917/Signal_1fb.root  
  //  https://indico.cern.ch/event/607726/contributions/2475151/attachments/1496594/2328915/Background_1fb.root
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //In order to see the contents of the file you can also use the following command
  Signal_file->ls();
  //when you see the contents there is a Tree whose name is "tree"
  //Now, define TTree by which we access a tree from the file "Signal_1fb.root" 
  TTree* signal_tree=(TTree*)Signal_file->Get("tree");
  //In order to see the contents of the Tree just use the following command 
  //this will show, the branch name, data type and branch number
  signal_tree->Print();
  //Now, we have to set the branch addresses of the tree
  double signal_mass;
  signal_tree->SetBranchAddress("invariantMass",&signal_mass);
  //Now, define the 1-D histogram for branch in order to display in the form of Histogram
  TH1F* signal_histo=new TH1F("signal_histo","",50,100,160);
  //Now, we have to get the number of Entries for the loop which we use to fill the  Histogram for the tree contents
  //The command GetEntries() get the no. of Entries from the Tree
  int signal_Entries=signal_tree->GetEntries();
  cout<<"No.of Entries of the Signal tree="<<signal_Entries<<endl;
  for(int i=0;i<signal_Entries;i++)
  {
    //This will run for each entry
    signal_tree->GetEntry(i);
    //Now, fill the Histogram 
    signal_histo->Fill(signal_mass);
  }
  signal_histo->Draw();
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //                             Set as background                                                                 // 
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TFile* background_file=new TFile("Background_1fb.root","READ");
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //   https://indico.cern.ch/event/607726/contributions/2475151/attachments/1496594/2328917/Signal_1fb.root  
  //  https://indico.cern.ch/event/607726/contributions/2475151/attachments/1496594/2328915/Background_1fb.root
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //In order to see the contents of the file you can also use the following command
  background_file->ls();
  //when you see the contents there is a Tree whose name is "tree"
  //Now, define TTree by which we access a tree from the file "Background_1fb.root" 
  TTree* background_tree=(TTree*)background_file->Get("tree");
  //In order to see the contents of the Tree just use the following command 
  //this will show, the branch name, data type and branch number
  background_tree->Print();
  //Now, we have to set the branch addresses of the tree
  double background_mass;
  background_tree->SetBranchAddress("invariantMass",&background_mass);
  //Now, define the 1-D histogram for branch in order to display in the form of Histogram
  TH1F* background_histo=new TH1F("background_histo","",50,100,160);
  //Now, we have to get the number of Entries for the loop which we use to fill the  Histogram for the tree contents
  //The command GetEntries() get the no. of Entries from the Tree
  int background_Entries=background_tree->GetEntries();
  cout<<"No.of Entries of the background tree="<<background_Entries<<endl;
  for(int i=0;i<background_Entries;i++)
  {
    //This will run for each entry
    background_tree->GetEntry(i);
    //Now, fill the Histogram 
    background_histo->Fill(background_mass);
  }
  background_histo->Draw("SAME");
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //           https://root.cern.ch/doc/master/classTHStack.html                                                  // 
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //Now, define a THStack in order to stack a no. of histograms of different process
  THStack* stack=new THStack("stack","Stacked_Histograms");
  //The order of stacking the histograms is:
  //first, stack the histogram with large number of events then add the histograms with less number of events like below
  stack->Add(background_histo);
  stack->Add(signal_histo);
  //cosmetics for stacked histograms
  background_histo->SetLineColor(kBlack);
  background_histo->SetFillColor(kBlue);
  signal_histo->SetLineColor(kBlack);
  signal_histo->SetFillColor(kRed);
  stack->Draw();
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //                           https://root.cern.ch/doc/v608/classTFile.html                                 // 
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //Now, make File in which we can save our outputs in a file, which we can see latex
  TFile* file=new TFile("stackedhisto.root","RECREATE");
  //now, write your output in a file
  signal_histo->Write();
  background_histo->Write();
  stack->Write();
  //after, writing the file, we have to close this
  file->Close();
}
