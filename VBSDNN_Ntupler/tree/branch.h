// jet constituent values
vector<float> pfcand_pt_log(30);
vector<float> pfcand_phirel(30);
vector<float> pfcand_etarel(30);
vector<float> pfcand_e_log(30);
int fj_isW, label_W_cq;
float fj_pt, fj_sdmass_fromsubjets;

//normal values
double vbs_jet1_pt;
double vbs_jet1_eta; 
double vbs_jet1_phi;
double vbs_jet1_m;
double vbs_jet1_flavor;

double vbs_jet2_pt;
double vbs_jet2_eta;
double vbs_jet2_phi;
double vbs_jet2_m;
double vbs_jet2_flavor;

double vbs_lep1_pt;
double vbs_lep1_eta;
double vbs_lep1_phi;
double vbs_lep1_pid;
    
double vbs_lep2_pt;
double vbs_lep2_eta;
double vbs_lep2_phi;
double vbs_lep2_pid;
    
double vbs_lep3_pt;
double vbs_lep3_eta;
double vbs_lep3_phi;
double vbs_lep3_pid;
   
double vbs_lep4_pt;
double vbs_lep4_eta;
double vbs_lep4_phi;
double vbs_lep4_pid;

double vbs_met;
double vbs_met_phi;
double vbs_met_eta;
    
double vbs_ll_helicity;
double vbs_tttl_helicity;

/*
//tree
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
*/

//values
double muon1_pt;
double muon1_eta;
double muon1_phi;
double muon1_pid;

double muon2_pt;
double muon2_eta;
double muon2_phi;
double muon2_pid;

double electron1_pt;
double electron1_eta;
double electron1_phi;
double electron1_pid;

double electron2_pt;
double electron2_eta;
double electron2_phi;
double electron2_pid;

//initial
void init(){
    fj_isW                      = 0;
    label_W_cq                  = 0;
    fj_pt                       = gRandom->Gaus(500,10);
    fj_sdmass_fromsubjets       = gRandom->Gaus(100,10);
    for(int t=0;t<30;t++){
        pfcand_pt_log[t] = -10000;
        pfcand_phirel[t] = -10000;
        pfcand_etarel[t] = -10000;
        pfcand_e_log[t]  = -10000;
    }

	vbs_jet1_pt		=	-10000;
	vbs_jet1_eta	=	-10000;
	vbs_jet1_phi	=	-10000;
	vbs_jet1_m		=	-10000;
	vbs_jet1_flavor	=	-10000;

	vbs_jet2_pt		=	-10000;
	vbs_jet2_eta	=	-10000;
	vbs_jet2_phi	=	-10000;
	vbs_jet2_m		=	-10000;
	vbs_jet2_flavor	=	-10000;

	vbs_lep1_pt		=	-10000;
	vbs_lep1_eta	=	-10000;
	vbs_lep1_phi	=	-10000;
	vbs_lep1_pid	=	-10000;

	vbs_lep2_pt		=	-10000;
	vbs_lep2_eta	=	-10000;
	vbs_lep2_phi	=	-10000;
	vbs_lep2_pid	=	-10000;

	vbs_lep3_pt		=	-10000;
	vbs_lep3_eta	=	-10000;
	vbs_lep3_phi	=	-10000;
	vbs_lep3_pid	=	-10000;

	vbs_lep4_pt		=	-10000;
	vbs_lep4_eta	=	-10000;
	vbs_lep4_phi	=	-10000;
	vbs_lep4_pid	=	-10000;

	vbs_met			=	-10000;
	vbs_met_phi		=	-10000;
	vbs_met_eta		=	-10000;

	muon1_pt		=	-10000;
 	muon1_eta		=	-10000; 
	muon1_phi		=	-10000;
	muon1_pid		=	-10000;
    
	muon2_pt		=	-10000;
	muon2_eta		=	-10000;	
	muon2_phi		=	-10000;
	muon2_pid		=	-10000;

	electron1_pt	=	-10000;
	electron1_eta	=	-10000;
	electron1_phi	=	-10000;
	electron1_pid	=	-10000;
    
	electron2_pt	=	-10000;
	electron2_eta	=	-10000;
	electron2_phi	=	-10000;
	electron2_pid	=	-10000;

}
