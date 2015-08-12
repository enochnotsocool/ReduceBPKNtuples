#ifndef RecoJetSelection_H
#define RecoJetSelection_H

#include "format.h"
#include "DPHI.h"

void RecoJetSelection(LepInfoBranches LepInfo, JetInfoBranches JetInfo, 
        int NMuons, int M_Index[], int NElectrons, int E_Index[], int &NJets, int *J_Index){

    double LJDR = 0.5;
    for(int nj=0;nj<JetInfo.Size;nj++){
        // Jet cleaning
        int dup_flag = 0;
        for(int nm=0;nm<NMuons;nm++){
            double dphi       = DPHI(JetInfo.Phi[nj],LepInfo.Phi[M_Index[nm]]);
            double deta       = fabs(JetInfo.Eta[nj]-LepInfo.Eta[M_Index[nm]]);
            double dR         = pow(dphi*dphi+deta*deta,0.5);
            if (dR<=LJDR) {
                dup_flag = 1;
                break;
            }
        }
        if(dup_flag) continue;
        for(int ne=0;ne<NElectrons;ne++){
            double dphi       = DPHI(JetInfo.Phi[nj],LepInfo.Phi[E_Index[ne]]);
            double deta       = fabs(JetInfo.Eta[nj]-LepInfo.Eta[E_Index[ne]]);
            double dR         = pow(dphi*dphi+deta*deta,0.5);
            if (dR<=LJDR) {
                dup_flag = 1;
                break;
            }
        }
        if(dup_flag) continue;

        // Jet selection
        if((JetInfo.JetIDLOOSE[nj]==1)&&
                (fabs(JetInfo.Pt[nj])>30) &&
                (fabs(JetInfo.Eta[nj])<2.4)
          ) {
            J_Index[NJets] = nj;
            NJets++;
        }
    }   

}

#endif
