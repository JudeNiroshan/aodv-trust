## -*- Mode: python; py-indent-offset: 4; indent-tabs-mode: nil; coding: utf-8; -*-

def build(bld):
    module = bld.create_ns3_module('aodv-trust', ['internet', 'wifi', 'applications', 'mesh', 'point-to-point', 'virtual-net-device'])
    module.includes = '.'
    module.source = [
        'model/aodv-id-cache.cc',
        'model/aodv-dpd.cc',
        'model/aodv-rtable.cc',
        'model/aodv-rqueue.cc',
        'model/aodv-packet.cc',
        'model/aodv-neighbor.cc',
        'model/aodv-routing-protocol.cc',
	'helper/aodv-trust-helper.cc',
        'model/TrustTableEntry.cc',
        'model/TrustTable.cc',
        'model/BackupTableEntry.cc',
        'model/BackupTable.cc',
        'model/NodeEntry.cc',
        'model/TestValueGenerator.cc',
        'model/DirTrustCal.cc',
        'model/DirTrustHelper.cc',
        'model/IndTrustCal.cc',
        'model/RecommendationTable.cc',
        'model/RecommendationTableEntry.cc',
        'model/TrustLevelClassifier.cc',
        'model/Spiral.cc',
        'model/TrustInfoReceiver.cc'
        ]

    aodv_test = bld.create_ns3_module_test_library('aodv-trust')
    aodv_test.source = [
        'test/aodv-test-suite.cc',
        ]

    headers = bld(features='ns3header')
    headers.module = 'aodv-trust'
    headers.source = [
        'model/aodv-id-cache.h',
        'model/aodv-dpd.h',
        'model/aodv-rtable.h',
        'model/aodv-rqueue.h',
        'model/aodv-packet.h',
        'model/aodv-neighbor.h',
        'model/aodv-routing-protocol.h',
        'helper/aodv-trust-helper.h',
        'model/TrustTableEntry.h',    
        'model/TrustTable.h',
        'model/BackupTable.h',
        'model/NodeEntry.h',
        'model/TestValueGenerator.h',
        'model/DirTrustCal.h',
        'model/DirTrustHelper.h',
        'model/IndTrustCal.h',
        'model/RecommendationTable.h',
        'model/RecommendationTableEntry.h',
        'model/TrustLevelClassifier.h',
        'model/Spiral.h',
        'model/TrustInfoReceiver.h'
        ]

    if bld.env['ENABLE_EXAMPLES']:
        bld.recurse('examples')

    bld.ns3_python_bindings()
