#!/bin/csh

source /cvmfs/cms.cern.ch/cmsset_default.csh

setenv SCRAM_ARCH slc5_amd64_gcc462

cd /cvmfs/cms.cern.ch/slc5_amd64_gcc462/cms/cmssw-patch/CMSSW_5_3_2_patch5/src;
cmsenv
cd -
