#ifndef RecoLooseLeptonSelection_H
#define RecoLooseLeptonSelection_H

#include "format.h"
#include "DPHI.h"
#include "UseEIDRhoCorIsoR03.h"

void RecoLooseLeptonSelection(EvtInfoBranches EvtInfo, LepInfoBranches LepInfo, int &NMuons, int *M_Index, int &NElectrons, int *E_Index,
        int &NLeptons, int *L_Index){

    double LLDR = 0.3;

    for(int nl=0;nl<LepInfo.Size;nl++){
        if((LepInfo.LeptonType[nl]==13)&&
                (fabs(LepInfo.Pt[nl])>10) &&
                (fabs(LepInfo.Eta[nl])<2.5) &&
                // Tight Muon
                (LepInfo.IsoRhoCorrR04[nl]/LepInfo.Pt[nl]<0.2) &&
                (LepInfo.MuType[nl] == 46) 
          ) {
            M_Index[NMuons] = nl;
            NMuons++;
            L_Index[NLeptons] = nl;
            NLeptons++;
        }else if((LepInfo.LeptonType[nl]==11)&&
                (fabs(LepInfo.Pt[nl])>20) &&
                //UseEIDMEDIUMRhoCorIsoR03(LepInfo,EvtInfo,nl)
                UseEIDRhoCorIsoR03(LepInfo,EvtInfo,nl,LOOSE)
                ){
            E_Index[NElectrons] = nl;
            NElectrons++;
            L_Index[NLeptons] = nl;
            NLeptons++;
        }
    }   

    // remove electron overlapping with muon
    const int n_index = NElectrons;
    int E_Index_temp[n_index]; 
    int NElectrons_temp = 0; 
    for(int fl=0;fl<n_index;fl++)   E_Index_temp[fl] = -1;
    for(int l1=0;l1<NElectrons;l1++){
        bool remove_electron = false;
        for(int l2=0;l2<NMuons;l2++){
            double dphi       = DPHI(LepInfo.Phi[M_Index[l2]],LepInfo.Phi[E_Index[l1]]);
            double deta       = fabs(LepInfo.Eta[M_Index[l2]]-LepInfo.Eta[E_Index[l1]]);
            double dR         = pow(dphi*dphi+deta*deta,0.5);
            if (dR<=LLDR) {
                remove_electron = true;
            }    
        }    
        if (remove_electron) continue;
        E_Index_temp[NElectrons_temp] = E_Index[l1];
        NElectrons_temp++;
    }    
    //if((NElectrons-NElectrons_temp)<0) std::cout<<"NElectrons-NElectrons_removed : "<<NElectrons-NElectrons_temp<<std::endl;
    NElectrons = NElectrons_temp;
    for(int fl=0;fl<n_index;fl++)   E_Index[fl] = E_Index_temp[fl];
}

#endif
