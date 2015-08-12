#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "format.h"
#include "iostream"
#include "vector"
#include "TStyle.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "string.h"
#include "TLorentzVector.h"
#include "math.h"
#include "TROOT.h"
#include "TSystem.h"
#include <exception>
#include "ReduceTree.h"
#include "fstream"
#include <map>
#include "TriggerBooking.h"

using namespace std;

void do_reduce(char *datatag = NULL,int isdata = 0);

void reduce_Samples()
{

	do_reduce("WGToLNuG_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
	do_reduce("ZGToLLG_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
    // background
    /*

do_reduce("TprimeTprimeToTgammaTgammainc_M-475_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TprimeTprimeToTgammaTgammainc_M-500_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TprimeTprimeToTgammaTgammainc_M-525_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TprimeTprimeToTgammaTgammainc_M-550_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TprimeTprimeToTgammaTgammainc_M-575_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TprimeTprimeToTgammaTgammainc_M-600_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TprimeTprimeToTgammaTgammainc_M-625_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TprimeTprimeToTgammaTgammainc_M-650_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TprimeTprimeToTgammaTgammainc_M-675_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TprimeTprimeToTgammaTgammainc_M-700_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TprimeTprimeToTgammaTgammainc_M-725_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TprimeTprimeToTgammaTgammainc_M-750_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TprimeTprimeToTgammaTgammainc_M-775_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TprimeTprimeToTgammaTgammainc_M-800_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);

     */
/*
do_reduce("DYJetsToLL_M-10To50filter_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("QCD_Pt-120to170_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v2",0);
do_reduce("QCD_Pt-15to30_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v2",0);
do_reduce("QCD_Pt-170to300_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("QCD_Pt-300to470_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("QCD_Pt-30to50_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("QCD_Pt-470to600_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("QCD_Pt-50to80_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("QCD_Pt-600to800_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("QCD_Pt-800to1000_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("QCD_Pt-80to120_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v2",0);
do_reduce("Tbar_s-channel_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("Tbar_t-channel_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("Tbar_tW-channel-DR_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("T_s-channel_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("T_t-channel_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v2",0);
do_reduce("TTGJets_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TTJets_MassiveBinDECAY_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TTJets_matchingdown_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TTJets_matchingup_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TTJets_scaledown_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TTJets_scaleup_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("T_tW-channel-DR_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TTWJets_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TTWWJets_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("TTZJets_8TeV-madgraph_v2_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("WJetsToLNu_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v2",0);
do_reduce("WW_TuneZ2star_8TeV_pythia6_tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("WWWJets_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("WZ_TuneZ2star_8TeV_pythia6_tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
do_reduce("ZZ_TuneZ2star_8TeV_pythia6_tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
	do_reduce("DiPhotonJets_8TeV-madgraph-tarball-v2_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
*/


    // 7TeV data
    // For run range (160404-180252)
    //do_reduce("DoubleElectron_Run2011B-PromptReco-v1_175832-176023",1);

    //do_reduce("Photon_Run2012A-13Jul2012-v1_190456-193686",1);
    //do_reduce("SinglePhoton_Run2012B-13Jul2012-v1_193752-196531",1);
    //do_reduce("SinglePhoton_Run2012C-24Aug2012-v1_198022-198523",1);


    //do_reduce("DoublePhoton_Run2012B-13Jul2012-v1_193752-196531",1);
    //do_reduce("DoublePhoton_Run2012C-24Aug2012-v2_198022-198523",1);

/*
//do_reduce("SingleElectron_Run2012A-13Jul2012-v1_190456-193686",1);
do_reduce("SingleElectron_Run2012B-13Jul2012-v1_193752-196531",1);
do_reduce("SingleElectron_Run2012C-24Aug2012-v1_198022-198523",1);
do_reduce("SingleElectron_Run2012C-PromptReco-v2_198934-203002",1);
//do_reduce("SingleMu_Run2012A-13Jul2012-v1_190456-193686",1);
do_reduce("SingleMu_Run2012B-13Jul2012-v1_193752-196531",1);
do_reduce("SingleMu_Run2012C-24Aug2012-v1_198022-198523",1);
do_reduce("SingleMu_Run2012C-PromptReco-v2_198934-203002",1);
*/

}

void do_reduce(char *datatag,int isdata)
{      

    if (datatag == NULL) {
        printf("USAGE: .x reduce.cc+(datatag)\n");	
        return;
    }

    int sample_style = 6; //[0,1,2,3,4,5,6] = [reduce,1filter,doublePhoton,dilepton,doublePhotondijet,trileptonfiler,1photon1lepton]
    //int sample_style = 6; //[0,1,2,3,4,5,6] = [reduce,1filter,doublePhoton,dilepton,doublePhotondijet,trileptonfiler,1photon1lepton]
    char buffer[1024];
    string data_folder="/wk3/cmsdata/Production_CMSSW536/Production_Data_DCSONLY_CMSSW53X_AOD/2012data/";
    string MC_folder="/wk3/cmsdata/Production_CMSSW536/Production_MC_CMSSW53X_AOD/2012MC/";
    //string data_folder="/wk3/cmsdata/Production_CMSSW53X/Production_Data_DCSONLY_CMSSW53X_AOD/2012data/";
    //string MC_folder="/wk3/cmsdata/Production_CMSSW53X/Production_MC_CMSSW53X_AOD/2012MC/";
    string folder;
    string folder1="bprimeKit/root";

    if(!isdata){
        folder=MC_folder+datatag;
    }else if(isdata==1){ 
        folder=data_folder+datatag;
    }
    // for test with data at 1pb-1
    TChain *root = new TChain(folder1.c_str());
    sprintf(buffer,"%s/*.root",folder.c_str());

    /*
       if(sample_style == 5) 
       sprintf(buffer,"/home/ymtzeng/ExcitedQuark/02172012/REDUCE_DATA_CODE/REDUCE_DATA_Summer11_dilepton/dilepton_%s.root",datatag);
     */

    std::cout<<"buffer : "<<buffer<<std::endl; 
    root->Add(buffer);

    printf("loading %s...\n",buffer);	

    EvtInfoBranches EvtInfo;
    LepInfoBranches LepInfo;
    JetInfoBranches JetInfo;
    PhotonInfoBranches PhotonInfo;
    EvtInfo.Register(root);
    LepInfo.Register(root,"PFLepInfo");
    JetInfo.Register(root,"PFJetInfo");
    PhotonInfo.Register(root,"PhotonInfo");

    ReduceTree(root);

    int nevents = 0;
    int nevents_total = root->GetEntries();	
    printf("test entries : %i \n",nevents_total);

    string sample_style_ = "reduce";
    if(sample_style == 1) sample_style_ = "1filter";
    if(sample_style == 2) sample_style_ = "diphoton";
    if(sample_style == 3) sample_style_ = "dilepton";
    if(sample_style == 4) sample_style_ = "diphotondijet";
    if(sample_style == 5) sample_style_ = "trilepton";
    if(sample_style == 6) sample_style_ = "1photon1lepton";
    if(sample_style == 7) sample_style_ = "1lepton4jets";
    if(isdata == 2) sample_style_ = "remove_duplicate";

    sprintf(buffer,"./REDUCE_DATA_Summer12_%s/%s_%s.root",sample_style_.c_str(),sample_style_.c_str(),datatag);
    std::cout<<buffer<<" " << datatag <<std::endl;

    TFile *newfile = new TFile(buffer,"recreate");
    newfile->mkdir("bprimeKit");
    newfile->cd("bprimeKit");
    TTree *newtree = root->CloneTree(0);

    for(int entry=0;entry<nevents_total;entry++) {		
        if ((entry%10000) == 0) 
            printf("Loading event #%d of %d.\n",entry,nevents_total);

        root->GetEntry(entry);


	int Nphotons = 0;
	for(int i=0;i<PhotonInfo.Size;i++) { 
		if(PhotonInfo.Pt[i]<=15) continue;
		Nphotons++;
	}

/*
        bool charge_flavor = false;
        for(int i=0;i<LepInfo.Size;i++) { 
            for(int j=i+1;j<LepInfo.Size;j++) { 
                if(LepInfo.LeptonType[i]==11&&LepInfo.LeptonType[j]==11){
                    if(LepInfo.Pt[i]<=15) continue;
                    if(!((fabs(LepInfo.Eta[i])<=1.478)||((fabs(LepInfo.Eta[i])<2.5)&&(fabs(LepInfo.Eta[i])>=1.55)))) continue;
                    if(LepInfo.Pt[j]<=15) continue;
                    if(!((fabs(LepInfo.Eta[j])<=1.478)||((fabs(LepInfo.Eta[j])<2.5)&&(fabs(LepInfo.Eta[j])>=1.55)))) continue;
                }else if(LepInfo.LeptonType[i]==13&&LepInfo.LeptonType[j]==13){
                    if(LepInfo.MuType[i]!=14) continue;
                    if(LepInfo.Pt[i]<=15) continue;
                    if(!(fabs(LepInfo.Eta[i])<2.5)) continue;
                    if(LepInfo.MuType[j]!=14) continue;
                    if(LepInfo.Pt[j]<=15) continue;
                    if(!(fabs(LepInfo.Eta[j])<2.5)) continue;
                }

                if(((LepInfo.Charge[i]+LepInfo.Charge[j])==0)&&(LepInfo.LeptonType[i]==LepInfo.LeptonType[j])) charge_flavor=true;
            }
        }
*/

        bool lep_1filter = false;
        bool OnelepTwojetfilter_ = false;
        int lep_numb = 0;
//        if(sample_style==1||sample_style==3||sample_style==4||sample_style==5||sample_style==6){
            for(int l=0;l<LepInfo.Size;l++) {
                if(LepInfo.LeptonType[l]==11){
                    if(!((fabs(LepInfo.Eta[l])<=1.478)||
                                ((fabs(LepInfo.Eta[l])<2.5)&&(fabs(LepInfo.Eta[l])>=1.55)))) continue;
                    if(LepInfo.Pt[l]<=15) continue;
                    lep_numb+=1;
                    lep_1filter = true;
                }
                if(LepInfo.LeptonType[l]==13){
                    if(LepInfo.MuType[l]!=14) continue;
                    if(!(fabs(LepInfo.Eta[l])<2.5)) continue;
                    if(LepInfo.Pt[l]<=15) continue;
                    lep_numb+=1;
                    lep_1filter = true;
                }
            }
        //}
//*/
            // Jet selection
            int NJets = 0;
            for(int nj=0;nj<JetInfo.Size;nj++){
                if((JetInfo.JetIDLOOSE[nj]==1)&&
                        (fabs(JetInfo.Pt[nj])>25) &&
                        (fabs(JetInfo.Eta[nj])<2.4)
                  ) { 
                    NJets++;
                }   
            }
            //if(lep_numb>=1&&NJets>=2) OnelepTwojetfilter_ = true;


/*
        bool accept = false;

        char DATA_TAG[128] = "results_7TeV_data";
        if(sample_style==0||sample_style==1){
            if(!strcmp(datatag,DATA_TAG)){
                if(EvtInfo.RunNo>=138000&&EvtInfo.RunNo<141900){
                    accept = 
                        ((int)EvtInfo.TrgBook[HLT_DoubleEle5_SW_L1R] == 1)||((int)EvtInfo.TrgBook[HLT_DoubleMu3] == 1);
                }else if(EvtInfo.RunNo<138000){
                    // don't pick these events because unstable prescaled-Ele-HLT
                    accept = false;
                }   

            }else{
                if (EvtInfo.TrgBook[HLT_DoubleEle10_SW_L1R]==1) accept = true;
                if (EvtInfo.TrgBook[HLT_DoubleMu3]==1) accept = true;
            }   
        }
*/


        if(sample_style==0){
            //if (!accept) continue;				
            //if(!charge_flavor) continue;
        }else if(sample_style==1){
            //if(!lep_1filter) continue;
            //if (!accept) continue;				
        }else if(sample_style==2){
            if(Nphotons<2) continue;
        }else if(sample_style==3){
            //if(!(lep_numb>1)) continue;
        }else if(sample_style==4){
            if(Nphotons<2) continue;
            if(NJets<2) continue;
            //if(!OnelepTwojetfilter_) continue;
        }else if(sample_style==5){
            //if(!(lep_numb>2)) continue;
        }else if(sample_style==6){
            if(Nphotons<1) continue;
            if(lep_numb<1) continue;
        }


        newtree->Fill(); // book this event to the new tree			
        nevents++;
    }

    printf("Finished - %d events saved from %d events.\n",nevents,nevents_total); 	
    newtree->Write();

    delete newtree;
    delete newfile;
}

