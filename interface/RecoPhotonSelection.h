#ifndef RecoPhotonSelection_H
#define RecoPhotonSelection_H

#include "format.h"
#include "DPHI.h"

void RecoPhotonSelection(LepInfoBranches LepInfo, PhotonInfoBranches PhotonInfo, 
        int NMuons, int M_Index[], int NElectrons, int E_Index[], int &NPhotons, int *P_Index,float RhoPU){

    RhoPU = 0;  // turn off Rho correction
    double LPDR = 0.3;
    for(int nl=0;nl<PhotonInfo.Size;nl++){
        // Medium Photon
        if(     (PhotonInfo.HoverE[nl]<0.05)&&
                (fabs(PhotonInfo.Pt[nl])>30) &&
                ((// Barrel
                  fabs(PhotonInfo.Eta[nl])<=1.4442 &&
		  PhotonInfo.passelectronveto[nl] &&
		  PhotonInfo.hadTowOverEm[nl] <=0.05 &&
                  PhotonInfo.SigmaIetaIeta[nl]<0.011 &&
		  (PhotonInfo.phoPFChIsoDR03[nl]<1.5) &&
		  (PhotonInfo.phoPFNeuIsoDR03[nl]<1.0+0.04*PhotonInfo.Pt[nl]) &&
		  (PhotonInfo.phoPFPhoIsoDR03[nl]<0.7+0.005*PhotonInfo.Pt[nl])
/*
                  (PhotonInfo.TrackIso[nl]<2.0+0.001*PhotonInfo.Pt[nl]+0.0167*RhoPU) &&
                  (PhotonInfo.EcalIso[nl]<4.2+0.006*PhotonInfo.Pt[nl]+0.183*RhoPU) &&
                  (PhotonInfo.HcalIso[nl]<2.2+0.0025*PhotonInfo.Pt[nl]+0.062*RhoPU)
*/
                  )
                 ||
                 (// Endcap
		  (fabs(PhotonInfo.Eta[nl])<2.4)&&(fabs(PhotonInfo.Eta[nl])>=1.566) &&
		  PhotonInfo.SigmaIetaIeta[nl]<0.033 &&
		  PhotonInfo.passelectronveto[nl] &&
		  PhotonInfo.hadTowOverEm[nl] <=0.05 &&
		  (PhotonInfo.phoPFChIsoDR03[nl]<1.2) &&
		  (PhotonInfo.phoPFNeuIsoDR03[nl]<1.5+0.04*PhotonInfo.Pt[nl]) &&
		  (PhotonInfo.phoPFPhoIsoDR03[nl]<1.0+0.005*PhotonInfo.Pt[nl])
		  /*
		     (PhotonInfo.TrackIso[nl]<2.0+0.001*PhotonInfo.Pt[nl]+0.032*RhoPU) &&
		     (PhotonInfo.EcalIso[nl]<4.2+0.006*PhotonInfo.Pt[nl]+0.090*RhoPU) &&
		     (PhotonInfo.HcalIso[nl]<2.2+0.0025*PhotonInfo.Pt[nl]+0.180*RhoPU) 
		   */
                 ))
          ){
            // Photon cleaning
            int dup_flag = 0;
            for(int nm=0;nm<NMuons;nm++){
                double dphi       = DPHI(PhotonInfo.Phi[nl],LepInfo.Phi[M_Index[nm]]);
                double deta       = fabs(PhotonInfo.Eta[nl]-LepInfo.Eta[M_Index[nm]]);
                double dR         = pow(dphi*dphi+deta*deta,0.5);
                if (dR<=LPDR) {
                    dup_flag = 1;
                    break;
                }   
            }   
            if(dup_flag) continue;
            dup_flag = 0;
            for(int ne=0;ne<NElectrons;ne++){
                double dphi       = DPHI(PhotonInfo.Phi[nl],LepInfo.Phi[E_Index[ne]]);
                double deta       = fabs(PhotonInfo.Eta[nl]-LepInfo.Eta[E_Index[ne]]);
                double dR         = pow(dphi*dphi+deta*deta,0.5);
                if (dR<=LPDR) {
                    dup_flag = 1;
                    break;
                }   
            }   
            if(dup_flag) continue;

            P_Index[NPhotons] = nl;
            NPhotons++;
        }
    }   

}

#endif
