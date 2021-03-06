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
#include "interface/RecoLeptonSelection.h"

using namespace std;

void do_reduce(char *datatag = NULL,int isdata = 0);

void reduce_Samples_merge_step2()
{

do_reduce("DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
    // For 536
    /*

	do_reduce("GJet_Pt40_doubleEMEnriched_TuneZ2star_8TeV-pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
	do_reduce("WGToLNuG_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
	do_reduce("ZGToLLG_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
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
//do_reduce("TTJets_matchingdown_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
//do_reduce("TTJets_matchingup_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
//do_reduce("TTJets_scaledown_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
//do_reduce("TTJets_scaleup_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",0);
*/
/*
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


// Okay version
/*
do_reduce("SingleElectron_Run2012A-13Jul2012-v1_190456-193686",1);
do_reduce("SingleElectron_Run2012B-13Jul2012-v1_193752-196531",1);
do_reduce("SingleElectron_Run2012C-24Aug2012-v1_198022-198523",1);
do_reduce("SingleElectron_Run2012C-PromptReco-v2_198934-201000",1);
*/
/*

do_reduce("SingleElectron_Run2012C-PromptReco-v2_201001-203002",1);
do_reduce("SingleElectron_Run2012D-PromptReco-v1_203773-205000",1);
do_reduce("SingleElectron_Run2012D-PromptReco-v1_205001-206000",1);
do_reduce("SingleElectron_Run2012D-PromptReco-v1_206001-207000",1);
do_reduce("SingleElectron_Run2012D-PromptReco-v1_207001-207500",1);
do_reduce("SingleElectron_Run2012D-PromptReco-v1_207501-208551",1);
do_reduce("SingleElectron_Run2012D-PromptReco-v1_208552-208686",1);
*/


/*
do_reduce("SingleMu_Run2012A-13Jul2012-v1_190456-193686",1);
do_reduce("SingleMu_Run2012B-13Jul2012-v1_193752-196531",1);
do_reduce("SingleMu_Run2012C-24Aug2012-v1_198022-198523",1);
do_reduce("SingleMu_Run2012C-PromptReco-v2_198934-203002",1);
do_reduce("SingleMu_Run2012C-PromptReco-v2_198934-203002_v2",1);
do_reduce("SingleMu_Run2012D-PromptReco-v1_203773-208551",1);
do_reduce("SingleMu_Run2012D-PromptReco-v1_203773-208551_v2",1);
do_reduce("SingleMu_Run2012D-PromptReco-v1_208552-208686",1);
*/

}

void do_reduce(char *datatag,int isdata)
{      

    if (datatag == NULL) {
        printf("USAGE: .x reduce.cc+(datatag)\n");	
        return;
    }

    int sample_style = 7; //[0,1,2,3,4,5,6] = [reduce,1filter,doublePhoton,dilepton,doublePhotondijet,trileptonfiler,1photon1lepton]
    //int sample_style = 6; //[0,1,2,3,4,5,6] = [reduce,1filter,doublePhoton,dilepton,doublePhotondijet,trileptonfiler,1photon1lepton]
    char buffer[1024];
    string sample_style_ = "reduce";
    if(sample_style == 1) sample_style_ = "1filter";
    if(sample_style == 2) sample_style_ = "diphoton";
    if(sample_style == 3) sample_style_ = "dilepton";
    if(sample_style == 4) sample_style_ = "diphotondijet";
    if(sample_style == 5) sample_style_ = "trilepton";
    if(sample_style == 6) sample_style_ = "1photon1lepton";
    if(sample_style == 7) sample_style_ = "1lepton4jets";
    if(isdata == 2) sample_style_ = "remove_duplicate";
    //string data_folder="/wk3/cmsdata/Production_CMSSW536/Production_Data_DCSONLY_CMSSW53X_AOD/2012data/";
    //string MC_folder="/wk3/cmsdata/Production_CMSSW536/Production_MC_CMSSW53X_AOD/2012MC/";
    string data_folder="./REDUCE_DATA_Summer12_"+sample_style_+"/";
    string MC_folder="./REDUCE_DATA_Summer12_"+sample_style_+"/";
    //string data_folder="/wk3/cmsdata/Production_CMSSW53X/Production_Data_DCSONLY_CMSSW53X_AOD/2012data/";
    //string MC_folder="/wk3/cmsdata/Production_CMSSW53X/Production_MC_CMSSW53X_AOD/2012MC/";
    string folder;
    string folder1="bprimeKit/root";

    if(!isdata){
        folder=MC_folder+sample_style_+"_"+datatag;
    }else if(isdata==1){ 
        folder=data_folder+sample_style_+"_"+datatag;
    }
    // for test with data at 1pb-1
    TChain *root = new TChain(folder1.c_str());
    sprintf(buffer,"%s*.root",folder.c_str());

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


    sprintf(buffer,"./REDUCE_DATA_Summer12_%s_id/%s_%s.root",sample_style_.c_str(),sample_style_.c_str(),datatag);
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

        int NMuons = 0;
        int NElectrons = 0;
        int NLeptons = 0;
        int M_Index[MAX_LEPTONS/2];
        int E_Index[MAX_LEPTONS/2];
        int L_Index[MAX_LEPTONS/2*2];
        for(int m=0;m<MAX_LEPTONS/2;m++) M_Index[m] = 0;
        for(int e=0;e<MAX_LEPTONS/2;e++) E_Index[e] = 0;
        for(int l=0;l<MAX_LEPTONS/2*2;l++) L_Index[l] = 0;
        RecoLeptonSelection(EvtInfo,LepInfo,NMuons,M_Index,NElectrons,E_Index,NLeptons,L_Index);


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
                    //if(LepInfo.MuType[l]!=14) continue;
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


        bool accept = false;
        if(true){
                    //DoublePh
            /*
                    if(EvtInfo.TrgBook[HLT_DoublePhoton70_v1]==1)    accept = true;
                    if(EvtInfo.TrgBook[HLT_DoublePhoton70_v3]==1)    accept = true;
                    if(EvtInfo.TrgBook[HLT_DoublePhoton70_v4]==1)    accept = true;
                    if(EvtInfo.TrgBook[HLT_DoublePhoton70_v5]==1)    accept = true;
                    if(EvtInfo.TrgBook[HLT_DoublePhoton70_v6]==1)    accept = true;
                    */
		if(!EvtInfo.McFlag&&NJets>3){

			// SingleLepton
			if(EvtInfo.TrgBook[HLT_IsoMu20_eta2p1_TriCentralPFJet30_v2]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_IsoMu20_eta2p1_TriCentralPFJet30_v3]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_IsoMu20_eta2p1_TriCentralPFJet30_v4]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_v1]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_v3]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_v4]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v1]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet45_35_25_v1]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet45_35_25_v2]==1)    accept = true;

			if(EvtInfo.TrgBook[HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFJet30_v2]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFJet30_v3]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFJet30_v8]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFJet30_v9]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFJet30_v10]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_v3]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_v4]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_v5]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v1]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet45_35_25_v1]==1)    accept = true;
			if(EvtInfo.TrgBook[HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet45_35_25_v2]==1)    accept = true;
		}else{
			if(NJets>3)
				accept = true;
		}

        }

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
        }else if(sample_style==7){
            if(NLeptons<1) continue;
            if(NJets<4) continue;
            if (!accept) continue;				
        }


        newtree->Fill(); // book this event to the new tree			
        nevents++;
    }

    printf("Finished - %d events saved from %d events.\n",nevents,nevents_total); 	
    newtree->Write();

    delete newtree;
    delete newfile;
}

