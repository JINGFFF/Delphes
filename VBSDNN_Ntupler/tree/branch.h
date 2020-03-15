//values
vector<float> pfcand_pt_log(30);
vector<float> pfcand_phirel(30);
vector<float> pfcand_etarel(30);
vector<float> pfcand_e_log(30);
int fj_isW, label_W_cq;
float fj_pt, fj_sdmass_fromsubjets;

//tree
TTree *tree = new TTree("tree","tree");
tree->Branch("pfcand_pt_log",&pfcand_pt_log);
tree->Branch("pfcand_etarel",&pfcand_etarel);
tree->Branch("pfcand_phirel",&pfcand_phirel);
tree->Branch("pfcand_e_log",&pfcand_e_log);
tree->Branch("fj_isW",&fj_isW);
tree->Branch("fj_pt",&fj_pt);
tree->Branch("label_W_cq",&label_W_cq);
tree->Branch("fj_sdmass_fromsubjets",&fj_sdmass_fromsubjets);

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
}

