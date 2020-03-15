vector<float> pfcand_pt_log(30);
vector<float> pfcand_phirel(30);
vector<float> pfcand_etarel(30);
vector<float> pfcand_e_log(30);
int fj_isW, label_W_cq;
float fj_pt, fj_sdmass_fromsubjets;

void init(){

    fj_isW 			= 0;
    label_W_cq 			= 0;    
    fj_pt 			= gRandom->Gaus(500,10); 
    fj_sdmass_fromsubjets 	= gRandom->Gaus(100,10);
    for(int t=0;t<30;t++){
	pfcand_pt_log[t] = -10000;
        pfcand_phirel[t] = -10000;
        pfcand_etarel[t] = -10000;
        pfcand_e_log[t]  = -10000;	
    }
}

void test1(){
    //gSystem->Load("libExRootAnalysis.so");
    gSystem->Load("/home/pengj/software/MG5_aMC_v2_6_6/Delphes/libDelphes.so");

    TFile* output = new TFile("out.root","recreate");
    TTree *tree = new TTree("tree","tree");
    tree->Branch("pfcand_pt_log",&pfcand_pt_log);
    tree->Branch("pfcand_etarel",&pfcand_etarel);
    tree->Branch("pfcand_phirel",&pfcand_phirel);
    tree->Branch("pfcand_e_log",&pfcand_e_log);
    tree->Branch("fj_isW",&fj_isW);
    tree->Branch("fj_pt",&fj_pt);
    tree->Branch("label_W_cq",&label_W_cq);
    tree->Branch("fj_sdmass_fromsubjets",&fj_sdmass_fromsubjets);

    TChain chain("Delphes");
    TString inputFile = "/home/pengj/work/machinelearing/ssww/data/test11.root";

    chain.Add(inputFile);
    ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
    Long64_t numberOfEntries = treeReader->GetEntries();

    TClonesArray *branchTower = treeReader->UseBranch("Tower");
    TClonesArray *branchParticle = treeReader->UseBranch("Particle");
    TClonesArray *branchEvent = treeReader->UseBranch("Event");
    TClonesArray *branchJet = treeReader->UseBranch("Jet");
    TClonesArray *branchMuon = treeReader->UseBranch("Muon");
    TClonesArray *branchElectron = treeReader->UseBranch("Electron");
    TClonesArray *branchMissingET = treeReader->UseBranch("MissingET");

    TObject *object1;
    TObject *object2;
    GenParticle *particle1;
    GenParticle *particle2;
    Tower *tower;
    Track *track;  

    for(int i=0; i<=numberOfEntries-1; i++){
	if (i%1000 == 1)cout<<i<<"/"<<numberOfEntries<<endl;
	//if(i>10000) break; 
       	treeReader->ReadEntry(i);
        //if(branchJet->GetEntries()<2) continue;

	//get jets information
	init();
	int j1c = 0, j2c = 0;
	
	for(int j=0; j<=1; j++){
	    //Jet *jet=(Jet*) branchJet->At(j);
	    //int njc = jet->Constituents.GetEntriesFast();
	    if(j==0 && branchJet->GetEntries()>=1){
		Jet *jet=(Jet*) branchJet->At(j);
	    	for(int j1 = 0; j1 < jet->Constituents.GetEntriesFast(); ++j1){
	    	    object1 = jet->Constituents.At(j1);
	    	    if(object1 == 0) {/*cout<<"0"<<endl;*/ continue;}
	    	    if(object1->IsA() == GenParticle::Class()){
	            	particle1 = (GenParticle*) object1;
		    	if(j1c<15){
	            	    pfcand_pt_log[j1c] = log10(particle1->PT);
        	    	    pfcand_phirel[j1c] = particle1->Phi;
            	    	    pfcand_etarel[j1c] = particle1->Eta;
         	    	    pfcand_e_log[j1c]  = log10(particle1->E);
		    	}
		    	j1c++;
	    	    }	
	    	}	
	    }	

	    if(j==1 &&branchJet->GetEntries()>=2){
		Jet *jet=(Jet*) branchJet->At(j);
        	for(int j2 = 0; j2 < jet->Constituents.GetEntriesFast(); ++j2){
            	    object2 = jet->Constituents.At(j2);
            	    if(object2 == 0) {/*cout<<"0"<<endl;*/ continue;}
            	    if(object2->IsA() == GenParticle::Class()){
                	particle2 = (GenParticle*) object2;
                	if(j2c<15){ 
                    	    pfcand_pt_log[j2c+15] = log10(particle2->PT);
                       	    pfcand_phirel[j2c+15] = particle2->Phi;
                    	    pfcand_etarel[j2c+15] = particle2->Eta;
                       	    pfcand_e_log[j2c+15]  = log10(particle2->E);
                	}
                	j2c++;
            	    }
        	}
	    }
	}
	tree->Fill();

    }
    output->cd();
    output->mkdir("deepntuplizer","deepntuplizer");
    deepntuplizer->cd();
    tree->Write();
    output->Close();

}
