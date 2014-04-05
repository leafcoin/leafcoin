// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    // How many times we expect transactions after the last checkpoint to
    // be slower. This number is a compromise, as it can't be accurate for
    // every system. When reindexing from a fast disk with a slow CPU, it
    // can be up to 20, while when downloading from a slow network with a
    // fast multicore CPU, it won't be much higher than 1.
    static const double fSigcheckVerificationFactor = 5.0;


    struct CCheckpointData {
        const MapCheckpoints *mapCheckpoints;
        int64 nTimeLastCheckpoint;
        int64 nTransactionsLastCheckpoint;
        double fTransactionsPerDay;
    };

    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
               ( 10, uint256("0xb7d642e9658e13a912685dd5c252da389db91c96e7daffbcae1c630e0243c31a"))
		       ( 16755, uint256("0x7a2d2354ffd776da35061ec983d0e38ffb01cb87a1e0e35ecb1b644f62dc4379"))
			   ( 17542, uint256("0xaa30d8b18eb39522e4f80bcf562abeef9a0db08b6855ebb70d96a9ab396dd8f3"))
               ( 18338, uint256("0x96fe9464024e09ebe95261f96ff01bfdc01553f7a800fb3656a34da4dfffbd6c"))
		( 18818, uint256("0x8057cf460b2b6b375148e4ac9e6c8b0193775d78079e7b2037f6e8d44185afc5"))
		( 18819, uint256("0x62e129b02411ae495ba43daa4dd8e87b912175ac5c23745e265f6c774d24b905"))
		( 18900, uint256("0x107034123b366f5de7642f75fb84d54c830da86b7c0f531dd843361e31d6fc7b"))
		( 18980, uint256("0xda3e72700b01f0c6ae111ba9fb43e0b5f8c2fe473db3a5a4a5ba9c12c8f37046"))

        ( 20000, uint256("0xf7101c175b6a838917ae31d266525c9f6035f7979cedfdd98b99f92fd360cf7c"))
        ( 21000, uint256("0x36d632e2080eebc62b73b758623ce0698c104ab7f2a3a90a51d5bcf107e55377"))
        ( 22000, uint256("0x05c9cc15a4c817d4e5b1c31ea783f83a216008a82813ee859796c26870c235c8"))\
        ( 23000, uint256("0x827503a75f90d30cce62e8dfc1b2eb28a88582d1c7f3ebba3d1cf64c944bd83b"))

        ( 25000, uint256("0x84436f98b9f13084aea974f1a225539475c320cddfaf29703543b893ce09f216"))
        ( 28000, uint256("0x3ecfd94e223d7ccd6629704fa8fa18cac68a159e82498c62804666dcbbc3c987"))
        ( 31000, uint256("0x9c415cc8067ec8261bc5efd3b9f7a83502ee579414ac3250fbaf17a653ab134e"))
        ( 35000, uint256("0x6bcc8911e1029971130a61f3ca81f8817eb96e1dcd0d70f28ae1e4bf78841a5a"))
        ( 40000, uint256("0xc7998d00fd7ffbca6c420c432af7d98d283a477cf2c1d5c937b560c136ad6b07"))

        ( 45000, uint256("0xd309fe76b0f7309d242126b12fa58d1db2b364ccba89f134dfd4a16983c8ba00"))
        ( 50000, uint256("0xdaf0a1c441241cc3aa2f64f59399e2a8fd0e6d1d2bdfed66c49fcdca4b8f4931"))
        ( 60000, uint256("0x1c7b7199033b0b8a29f27f857b5c7976007d68f0cfd821f94c62fcdee156497d"))
        ( 70000, uint256("0xb21d73697594d274fd462badc913ad2c3346b7ddba6a38c088b96a02d3f293e7"))

        ( 73000, uint256("0x41c8b855cf26b1d7d1ae0c509655a012cb106d1d167ac8ddf60d2dca5956cd69"))
        ( 76000, uint256("0xe8204ebe42333ef3b11499bf4d35424d5b7d62ccf5d6052bff6c87bc573fa543"))
        ( 78000, uint256("0x06f3540e284ac1ab39c06092e4684ded30e4a8a4357e3105262d67640de81357"))

        ( 80328, uint256("203f3a0a2cea095261d3fb916b5bd7f0b4e35b686d2a857b56d41dbb1fedcd6e"))

            ( 85000, uint256("4da76b1992f3b56a9b7a2201ae471d61f48ebbfe3d6ad995d52caedd1db6554a"))

            ( 90000, uint256("5cf30f47a845b1c829c481c4c77fc95e9963f91af4f02a9ebbff3f3ca00f7cb1"))

            ( 92398, uint256("7ec135732f8b6df18b78415f6a619ec2ecb0c5890a8c9cdf5e76dd82717e8f2c"))

            ( 94618, uint256("9c38f4696c58a5e1a36871ac8795ad7296e734ae2f01ab75298c8b6dca71ccfa"))
		

	;
    static const CCheckpointData data = {
        &mapCheckpoints,
        1396740989 , // * UNIX timestamp of last checkpoint block
        581048,    // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        8000.0     // * estimated number of transactions per day after checkpoint
    };

    static MapCheckpoints mapCheckpointsTestnet = 
        boost::assign::map_list_of
        (     0, uint256("0xb78197f0e175697646db1f738edc1ffdcb30588ebe70e7e16026489076577061"))
        ;
    static const CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        1369685559,
        37581,
        300
    };

    const CCheckpointData &Checkpoints() {
        if (fTestNet)
            return dataTestnet;
        else
            return data;
    }

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints
        if (!GetBoolArg("-checkpoints", true))
            return true;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    // Guess how far we are in the verification process at the given block index
    double GuessVerificationProgress(CBlockIndex *pindex) {
        if (pindex==NULL)
            return 0.0;

        int64 nNow = time(NULL);

        double fWorkBefore = 0.0; // Amount of work done before pindex
        double fWorkAfter = 0.0;  // Amount of work left after pindex (estimated)
        // Work is defined as: 1.0 per transaction before the last checkoint, and
        // fSigcheckVerificationFactor per transaction after.

        const CCheckpointData &data = Checkpoints();

        if (pindex->nChainTx <= data.nTransactionsLastCheckpoint) {
            double nCheapBefore = pindex->nChainTx;
            double nCheapAfter = data.nTransactionsLastCheckpoint - pindex->nChainTx;
            double nExpensiveAfter = (nNow - data.nTimeLastCheckpoint)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore;
            fWorkAfter = nCheapAfter + nExpensiveAfter*fSigcheckVerificationFactor;
        } else {
            double nCheapBefore = data.nTransactionsLastCheckpoint;
            double nExpensiveBefore = pindex->nChainTx - data.nTransactionsLastCheckpoint;
            double nExpensiveAfter = (nNow - pindex->nTime)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore + nExpensiveBefore*fSigcheckVerificationFactor;
            fWorkAfter = nExpensiveAfter*fSigcheckVerificationFactor;
        }

        return fWorkBefore / (fWorkBefore + fWorkAfter);
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0; // Testnet has no checkpoints
        if (!GetBoolArg("-checkpoints", true))
            return 0;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL; // Testnet has no checkpoints
        if (!GetBoolArg("-checkpoints", true))
            return NULL;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
    
    uint256 GetLatestHardenedCheckpoint()
    {
        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;
        return (checkpoints.rbegin()->second);
    }
}
