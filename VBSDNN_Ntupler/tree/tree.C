#include "branch.h"

void tree(){
    //lib
    gSystem->Load("/home/pengj/software/MG5_aMC_v2_6_6/Delphes/libDelphes.so");

    //TFile* output = new TFile("out.root","recreate");
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

	tree->Branch("vbs_jet1_pt",&vbs_jet1_pt);
	tree->Branch("vbs_jet1_eta",&vbs_jet1_eta);
	tree->Branch("vbs_jet1_phi",&vbs_jet1_phi);
	tree->Branch("vbs_jet1_m",&vbs_jet1_m);
	tree->Branch("vbs_jet1_flavor",&vbs_jet1_flavor);

	tree->Branch("vbs_jet2_pt",&vbs_jet2_pt);
	tree->Branch("vbs_jet2_eta",&vbs_jet2_eta);
	tree->Branch("vbs_jet2_phi",&vbs_jet2_phi);
	tree->Branch("vbs_jet2_m",&vbs_jet2_m);
	tree->Branch("vbs_jet2_flavor",&vbs_jet2_flavor);

	tree->Branch("vbs_lep1_pt",&vbs_lep1_pt);
	tree->Branch("vbs_lep1_eta",&vbs_lep1_eta);
	tree->Branch("vbs_lep1_phi",&vbs_lep1_phi);

	tree->Branch("vbs_lep2_pt",&vbs_lep2_pt);
	tree->Branch("vbs_lep2_eta",&vbs_lep2_eta);
	tree->Branch("vbs_lep2_phi",&vbs_lep2_phi);

	tree->Branch("vbs_lep3_pt",&vbs_lep3_pt);
	tree->Branch("vbs_lep3_eta",&vbs_lep3_eta);
	tree->Branch("vbs_lep3_phi",&vbs_lep3_phi);

	tree->Branch("vbs_lep4_pt",&vbs_lep4_pt);
	tree->Branch("vbs_lep4_eta",&vbs_lep4_eta);
	tree->Branch("vbs_lep4_phi",&vbs_lep4_phi);

	tree->Branch("vbs_met",&vbs_met);
	tree->Branch("vbs_met_eta",&vbs_met_eta);
	tree->Branch("vbs_met_phi",&vbs_met_phi);


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
	    	if(j==0 && branchJet->GetEntries()>=1){
				Jet *jet=(Jet*) branchJet->At(j);

                vbs_jet1_pt = jet->PT;
                vbs_jet1_eta = jet->Eta;
                vbs_jet1_phi = jet->Phi;
                vbs_jet1_m = jet->Mass;
                vbs_jet1_flavor = jet->Flavor;

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

                vbs_jet2_pt = jet->PT;
                vbs_jet2_eta = jet->Eta;
                vbs_jet2_phi = jet->Phi;
                vbs_jet2_m = jet->Mass;
                vbs_jet2_flavor = jet->Flavor;

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


	// info of muon
        if(branchMuon->GetEntries() <= 0) ;

        else if(branchMuon->GetEntries() == 1){
            Muon *mu1 = (Muon*) branchMuon->At(0);

            muon1_pt    = mu1->PT; 
			muon1_eta    = mu1->Eta; 
			muon1_phi   = mu1->Phi; 
			muon1_pid  = 13.*mu1->Charge;
        }

        else if(branchMuon->GetEntries() >= 2){
            Muon *mu1 = (Muon*) branchMuon->At(0);
            Muon *mu2 = (Muon*) branchMuon->At(1);

            muon1_pt    = mu1->PT; 
			muon1_eta    = mu1->Eta; 
			muon1_phi   = mu1->Phi; 
			muon1_pid  = 13.*mu1->Charge;
            muon2_pt    = mu2->PT; 
			muon2_eta    = mu2->Eta; 
			muon2_phi   = mu2->Phi; 
			muon2_pid  = 13.*mu2->Charge;
        }

	// info of electron
        if(branchElectron->GetEntries() <= 0) ;

        else if(branchElectron->GetEntries() == 1){
            Electron *ele1 = (Electron*) branchElectron->At(0);

            electron1_pt    = ele1->PT; 
			electron1_eta    = ele1->Eta; 
			electron1_phi   = ele1->Phi; 
			electron1_pid  = 11.*ele1->Charge;
        }

        else if(branchElectron->GetEntries() >= 2){
            Electron *ele1 = (Electron*) branchElectron->At(0);
            Electron *ele2 = (Electron*) branchElectron->At(1);

            electron1_pt    = ele1->PT; 
			electron1_eta    = ele1->Eta; 
			electron1_phi   = ele1->Phi; 
			electron1_pid  = 11.*ele1->Charge;
            electron2_pt    = ele2->PT; 
			electron2_eta    = ele2->Eta; 
			electron2_phi   = ele2->Phi; 
			electron2_pid  = 11.*ele2->Charge;
        }

	//leading vbs_lepton info
	// (1) m1 > m2 > e1
        if(muon2_pt > electron1_pt){
            vbs_lep1_pt = muon1_pt; 
			vbs_lep1_eta = muon1_eta; 
			vbs_lep1_phi = muon1_phi; 
			vbs_lep1_pid = muon1_pid;
            vbs_lep2_pt = muon2_pt; 
			vbs_lep2_eta = muon2_eta; 
			vbs_lep2_phi = muon2_phi; 
			vbs_lep2_pid = muon2_pid;

        }

        // (2) m1> e1 > m2
        if(muon1_pt > electron1_pt && electron1_pt > muon2_pt){
            vbs_lep1_pt = muon1_pt; 
			vbs_lep1_eta = muon1_eta; 
			vbs_lep1_phi = muon1_phi; 
			vbs_lep1_pid = muon1_pid;
            vbs_lep2_pt = electron1_pt; 
			vbs_lep2_eta = electron1_eta; 
			vbs_lep2_phi = electron1_phi; 
			vbs_lep2_pid = electron1_pid;

        }

        // (3) e1 > m1 > e2
        if(electron1_pt > muon1_pt && muon1_pt > electron2_pt){
            vbs_lep1_pt = electron1_pt; 
			vbs_lep1_eta = electron1_eta; 
			vbs_lep1_phi = electron1_phi; 
			vbs_lep1_pid = electron1_pid;
            vbs_lep2_pt = muon1_pt; 
			vbs_lep2_eta = muon1_eta; 
			vbs_lep2_phi = muon1_phi; 
			vbs_lep2_pid = muon1_pid;

        }

        // (4) e1 > e2 > m1
        if(electron2_pt > muon1_pt ){
            vbs_lep1_pt = electron1_pt; 
			vbs_lep1_eta = electron1_eta; 
			vbs_lep1_phi = electron1_phi; 
			vbs_lep1_pid = electron1_pid;
            vbs_lep2_pt = electron2_pt; 
			vbs_lep2_eta = electron2_eta; 
			vbs_lep2_phi = electron2_phi; 
			vbs_lep2_pid = electron2_pid;

        }
	
	// info of met
        MissingET *Met = (MissingET*) branchMissingET->At(0);
        vbs_met     = Met->MET;
        vbs_met_phi = Met->Phi;
        vbs_met_eta = Met->Eta;

/*
        //apply selections
        TLorentzVector j1, j2, lep1, lep2;

        j1.SetPtEtaPhiM(vbs_jet1_pt,vbs_jet1_eta,vbs_jet1_phi,vbs_jet1_m);
        j2.SetPtEtaPhiM(vbs_jet2_pt,vbs_jet2_eta,vbs_jet2_phi,vbs_jet2_m);

        lep1.SetPtEtaPhiM(vbs_lep1_pt,vbs_lep1_eta,vbs_lep1_phi,0.);
        lep2.SetPtEtaPhiM(vbs_lep2_pt,vbs_lep2_eta,vbs_lep2_phi,0.);

        double deta_jj = jet1_eta-jet2_eta;
        double mjj = (j1+j2).M();
        double m_ll = (lep1+lep2).M();
        double deta_ll = (lep1+lep2).Eta();
*/
		cout<<vbs_lep1_pid<<endl;
		tree->Fill();

    }

    output->cd();
    output->mkdir("deepntuplizer","deepntuplizer");
    deepntuplizer->cd();
    tree->Write();
    output->Close();

}
