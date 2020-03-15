'''
Description on how to produce metadata file.
'''

input_filter = r'Tau|htata'
treename = 'deepntuplizer/tree'
reweight_events = -1
reweight_bins = [list(range(200, 2051, 50)), [-10000, 10000]]
metadata_events = 1000000
selection = '''pfcand_pt_log>0'''
var_groups = {
    # 'group_name': ( ('regex1', 'regex2', ...), list_length )
    'pfcand': (('pfcand_',), 100),
    'sv': (('sv_',), 7),
    }
var_blacklist = [
    ]
var_no_transform_branches = [
    'fj_isW',
    ]
label_list = [
              ]
reweight_var = []
reweight_classes = [
    #'fj_isTop',
    'fj_isW',
    ]
reweight_method = 'flat'
scale_method = 'max'
var_img = None
var_pos = None
n_pixels = None
img_ranges = None
