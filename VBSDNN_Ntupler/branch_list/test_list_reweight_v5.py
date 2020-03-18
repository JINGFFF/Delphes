'''
Description on how to produce metadata file.
'''

input_filter = r'Tau|htata'
treename = 'deepntuplizer/tree'
reweight_events = -1
reweight_bins = [list(range(200, 2051, 50)), [-10000, 10000]]
metadata_events = 1000000
#selection = '''jet_tightId'''
selection = '''vbs_jet1_pt>0'''
var_groups = {
    # 'group_name': ( ('regex1', 'regex2', ...), list_length )
    'pfcand': (('pfcand_',), 60),
    'vbs': (('vbs_',), 1),
    }
var_blacklist = [
    'fj_gen_pt',
    'fj_gen_eta',

    'fj_isBB',
    'fj_isNonBB',

    'n_pfcands',
    'n_tracks',
    'n_sv',

    'pfcand_btagJetDistSig',
    ]
var_no_transform_branches = [
    #'event_no',
    #'fj_isW', 

    #"fj_tau21",
    ]
label_list = [#'label_Top_bcq', 'label_Top_bqq', 'label_Top_bc', 'label_Top_bq',
              'label_sig', 'label_bkg',
              #'label_Z_bb', 'label_Z_cc', 'label_Z_qq',
              #'label_H_bb', 'label_H_cc', 'label_H_qqqq',
              #'label_QCD_bb', 'label_QCD_cc', 'label_QCD_b', 'label_QCD_c', 'label_QCD_others',
              ]
reweight_var = ['vbs_jet1_pt','vbs_jet2_pt']
#reweight_var = ['fj_pt']
reweight_classes = [
    #'fj_isTop',
    'fj_isW',
    #'fj_isZ',
    #'label_H_bb', 'label_H_cc', 'label_H_qqqq',  # H_bb, H_cc class_wgt divided by 2, H_qqqq devided by ~4-5 to become 1
    #'fj_isQCD',
    ]
reweight_method = 'flat'
scale_method = 'max'
var_img = None
var_pos = None
n_pixels = None
img_ranges = None
