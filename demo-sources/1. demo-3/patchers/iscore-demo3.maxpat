{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 1,
			"architecture" : "x86",
			"modernui" : 1
		}
,
		"rect" : [ 292.0, 161.0, 1184.0, 821.0 ],
		"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
		"editing_bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
		"bglocked" : 0,
		"openinpresentation" : 1,
		"default_fontsize" : 10.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 0,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"boxes" : [ 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-9",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "mgu_filter~.module.maxpat",
					"numinlets" : 2,
					"numoutlets" : 2,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 508.0, 537.5, 300.0, 315.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 335.0, 426.0, 300.0, 315.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"autofit" : 1,
					"forceaspect" : 1,
					"id" : "obj-2",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "jit_matrix" ],
					"patching_rect" : [ 860.0, 156.0, 100.0, 100.0 ],
					"pic" : "/Users/meegooh/Desktop/main/archives_work/_demo-iscore/iscore-demo3/media/i-score.png",
					"presentation" : 1,
					"presentation_rect" : [ 100.0, 28.0, 100.0, 100.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-19",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1013.0, 617.0, 150.0, 18.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 1018.0, 441.5, 36.0, 29.0 ],
					"style" : "",
					"text" : "audio on/off"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 16.0,
					"id" : "obj-5",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 391.0, 42.0, 245.0, 42.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 38.0, 141.0, 224.0, 42.0 ],
					"style" : "",
					"text" : "i-score\ndemo #3",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"args" : [ "grn" ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-12",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "mgu_granary~.module.maxpat",
					"numinlets" : 2,
					"numoutlets" : 2,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 38.0, 28.0, 300.0, 420.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 25.0, 198.0, 300.0, 420.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 472.0, 472.0, 104.0, 20.0 ],
					"style" : "",
					"text" : "MinuitInterface demo"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-7",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 38.0, 904.0, 450.0, 20.0 ],
					"style" : "",
					"text" : "dac~ 1 2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 1150.0, 607.0, 45.0, 45.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 381.5, 65.5, 49.0, 49.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"args" : [ "vrb" ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-4",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "mgu_zita~.module.maxpat",
					"numinlets" : 2,
					"numoutlets" : 2,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 38.0, 703.0, 450.0, 210.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 640.0, 426.0, 450.0, 210.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"args" : [ "fshift" ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-3",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "mgu_fshifter~.module.maxpat",
					"numinlets" : 2,
					"numoutlets" : 3,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal", "signal", "" ],
					"patching_rect" : [ 38.0, 458.0, 150.0, 70.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 335.0, 198.0, 150.0, 70.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"args" : [ "chrs" ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-1",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "mgu_chorus~.module.maxpat",
					"numinlets" : 2,
					"numoutlets" : 2,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 38.0, 537.5, 450.0, 140.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 335.0, 276.0, 450.0, 140.0 ],
					"viewvisibility" : 1
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-12", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 113.0, 534.0, 478.5, 534.0 ],
					"source" : [ "obj-3", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-9", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-9", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-1::obj-1::obj-7" : [ "indel-right", "indel-right", 0 ],
			"obj-1::obj-1::obj-6" : [ "indel-left", "indel-left", 0 ],
			"obj-4::obj-1::obj-19" : [ "live.dial[10]", "lo RT60", 0 ],
			"obj-4::obj-1::obj-18" : [ "live.dial[11]", "LF X", 0 ],
			"obj-4::obj-1::obj-17" : [ "fb-left[9]", "in-delay", 0 ],
			"obj-4::obj-1::obj-27" : [ "live.dial[7]", "eq2 freq", 0 ],
			"obj-1::obj-1::obj-4" : [ "depth", "depth", 0 ],
			"obj-1::obj-1::obj-20" : [ "fb-right", "fb-right", 0 ],
			"obj-1::obj-1::obj-17" : [ "fb-left", "fb-left", 0 ],
			"obj-1::obj-1::obj-11" : [ "live.numbox[5]", "live.numbox", 0 ],
			"obj-4::obj-1::obj-30" : [ "live.dial[5]", "dry/wet", 0 ],
			"obj-3::obj-1::obj-7" : [ "live.toggle", "live.toggle", 0 ],
			"obj-4::obj-1::obj-26" : [ "live.dial[8]", "eq1 freq", 0 ],
			"obj-3::obj-1::obj-11" : [ "live.numbox[3]", "live.numbox", 0 ],
			"obj-4::obj-1::obj-29" : [ "fb-left[10]", "eq2 lvl", 0 ],
			"obj-4::obj-1::obj-25" : [ "live.dial[9]", "HF DAMP", 0 ],
			"obj-4::obj-1::obj-28" : [ "fb-left[11]", "eq1 lvl", 0 ],
			"obj-12::obj-1::obj-26" : [ "live.toggle[1]", "live.toggle", 0 ],
			"obj-4::obj-1::obj-20" : [ "fb-right[9]", "mid RT60", 0 ]
		}
,
		"dependency_cache" : [ 			{
				"name" : "mgu_chorus~.module.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_chorus~.model.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_chorus~.model-poly.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "slv.chorus-mtos.gendsp",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/code",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "slv.lfnoise.gendsp",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/code",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_chorus~.view.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_fshifter~.module.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_fshifter~.model.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_fshifter~.view.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_zita~.module.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_zita~.model.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_zita~.model-poly.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_zita~.view.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "MinuitInterface.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_granary~.module.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_granary~.model.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_granulator-poly.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "pan2.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_granary~.view.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "wfmodes.png",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/media",
				"type" : "PNG ",
				"implicit" : 1
			}
, 			{
				"name" : "wfknob.png",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/media",
				"type" : "PNG ",
				"implicit" : 1
			}
, 			{
				"name" : "i-score.png",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/media",
				"type" : "PNG ",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_filter~.module.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_filter~.model.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_filter~.model-poly.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mgu_filter~.view.maxpat",
				"bootpath" : "~/Dropbox/_virta/_conf-iscore/1-demo#3/iscore-demo3/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "j.in~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "j.out~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "j.model.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "j.parameter.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "j.ui.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "j.view.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "j.remote.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "j.receive~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "zita_rev1~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "j.modular.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "j.receive.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "j.message.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "j.limiter~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "j.send.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
