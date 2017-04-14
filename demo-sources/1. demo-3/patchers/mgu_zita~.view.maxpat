{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 6,
			"minor" : 1,
			"revision" : 7,
			"architecture" : "x86"
		}
,
		"rect" : [ 334.0, 471.0, 450.0, 210.0 ],
		"bgcolor" : [ 1.0, 1.0, 1.0, 0.0 ],
		"bglocked" : 0,
		"openinpresentation" : 1,
		"default_fontsize" : 10.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 0,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-31",
					"maxclass" : "live.line",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 520.0, 267.0, 5.0, 100.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 367.0, 19.75, 5.0, 190.25 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "live.line",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 505.0, 252.0, 5.0, 100.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 229.0, 19.75, 5.0, 190.25 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "live.line",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 490.0, 237.0, 5.0, 100.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 80.0, 19.75, 5.0, 190.25 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"frgb" : 0.0,
					"id" : "obj-39",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 52.5, 256.0, 75.0, 18.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 11.5, 35.0, 55.0, 18.0 ],
					"text" : "Input",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"frgb" : 0.0,
					"id" : "obj-33",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 264.385376, 186.0, 161.0, 18.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 101.0, 28.0, 105.0, 29.0 ],
					"text" : "Decay times in bands",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"fontface" : 2,
					"id" : "obj-17",
					"maxclass" : "live.slider",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 68.0, 302.0, 44.0, 107.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 17.0, 65.5, 44.0, 107.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "fb-left[9]",
							"parameter_shortname" : "in-delay",
							"parameter_type" : 1,
							"parameter_mmin" : 20.0,
							"parameter_mmax" : 100.0,
							"parameter_unitstyle" : 2
						}

					}
,
					"varname" : "live.slider"
				}

			}
, 			{
				"box" : 				{
					"activedialcolor" : [ 0.619608, 0.0, 0.360784, 0.698039 ],
					"annotation" : "none",
					"fontface" : 0,
					"id" : "obj-30",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 853.0, 513.0, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 387.0, 149.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "live.dial[5]",
							"parameter_shortname" : "dry/wet",
							"parameter_type" : 0,
							"parameter_mmin" : -1.0,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"tricolor" : [ 0.619608, 0.0, 0.360784, 0.698039 ],
					"varname" : "live.dial[6]"
				}

			}
, 			{
				"box" : 				{
					"annotation" : "none",
					"fontface" : 2,
					"id" : "obj-29",
					"maxclass" : "live.slider",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 697.0, 501.0, 43.0, 107.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 300.0, 90.0, 43.0, 107.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "fb-left[10]",
							"parameter_shortname" : "eq2 lvl",
							"parameter_type" : 0,
							"parameter_mmin" : -15.0,
							"parameter_mmax" : 15.0,
							"parameter_unitstyle" : 4
						}

					}
,
					"tricolor" : [ 0.797236, 0.45096, 0.198464, 1.0 ],
					"varname" : "live.slider[2]"
				}

			}
, 			{
				"box" : 				{
					"annotation" : "none",
					"fontface" : 2,
					"id" : "obj-28",
					"maxclass" : "live.slider",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 564.0, 501.0, 43.0, 107.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 247.0, 90.0, 43.0, 107.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "fb-left[11]",
							"parameter_shortname" : "eq1 lvl",
							"parameter_type" : 0,
							"parameter_mmin" : -15.0,
							"parameter_mmax" : 15.0,
							"parameter_unitstyle" : 4
						}

					}
,
					"tricolor" : [ 0.797236, 0.45096, 0.198464, 1.0 ],
					"trioncolor" : [ 0.797236, 0.45096, 0.198464, 1.0 ],
					"varname" : "live.slider[1]"
				}

			}
, 			{
				"box" : 				{
					"annotation" : "none",
					"fontface" : 0,
					"id" : "obj-27",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 684.0, 353.0, 58.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 300.0, 28.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "live.dial[7]",
							"parameter_shortname" : "eq2 freq",
							"parameter_type" : 1,
							"parameter_mmin" : 40.0,
							"parameter_mmax" : 295.0,
							"parameter_unitstyle" : 3
						}

					}
,
					"varname" : "live.dial[5]"
				}

			}
, 			{
				"box" : 				{
					"annotation" : "none",
					"fontface" : 0,
					"id" : "obj-26",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 564.0, 353.0, 58.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 247.0, 28.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "live.dial[8]",
							"parameter_shortname" : "eq1 freq",
							"parameter_type" : 1,
							"parameter_mmin" : 40.0,
							"parameter_mmax" : 295.0,
							"parameter_unitstyle" : 3
						}

					}
,
					"varname" : "live.dial[4]"
				}

			}
, 			{
				"box" : 				{
					"annotation" : "none",
					"fontface" : 0,
					"id" : "obj-25",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 382.770752, 353.0, 77.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.0, 69.5, 65.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "live.dial[9]",
							"parameter_shortname" : "HF DAMP",
							"parameter_type" : 1,
							"parameter_mmin" : 6000.0,
							"parameter_mmax" : 6255.0,
							"parameter_unitstyle" : 3
						}

					}
,
					"varname" : "live.dial[3]"
				}

			}
, 			{
				"box" : 				{
					"annotation" : "none",
					"fontface" : 0,
					"id" : "obj-20",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 374.078064, 236.0, 58.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 95.0, 129.5, 52.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "fb-right[9]",
							"parameter_shortname" : "mid RT60",
							"parameter_type" : 0,
							"parameter_mmax" : 8.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "live.dial[2]"
				}

			}
, 			{
				"box" : 				{
					"annotation" : "none",
					"fontface" : 0,
					"id" : "obj-19",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 253.078064, 236.0, 58.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 99.0, 69.5, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "live.dial[10]",
							"parameter_shortname" : "lo RT60",
							"parameter_type" : 0,
							"parameter_mmax" : 8.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "live.dial[1]"
				}

			}
, 			{
				"box" : 				{
					"annotation" : "none",
					"fontface" : 0,
					"id" : "obj-18",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 253.078064, 353.0, 58.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 160.0, 129.5, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "live.dial[11]",
							"parameter_shortname" : "LF X",
							"parameter_type" : 0,
							"parameter_mmin" : 50.0,
							"parameter_mmax" : 1000.0,
							"parameter_unitstyle" : 3
						}

					}
,
					"varname" : "live.dial"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.658824, 0.658824, 0.721569, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "" ],
					"patching_rect" : [ 374.078064, 294.0, 86.0, 18.0 ],
					"text" : "j.remote mid-rt60"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.658824, 0.658824, 0.721569, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-13",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "" ],
					"patching_rect" : [ 253.078064, 294.0, 78.0, 18.0 ],
					"text" : "j.remote lo-rt60"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.658824, 0.658824, 0.721569, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-11",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "" ],
					"patching_rect" : [ 697.0, 629.0, 79.0, 18.0 ],
					"text" : "j.remote eq2-lvl"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.658824, 0.658824, 0.721569, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-12",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "" ],
					"patching_rect" : [ 684.0, 408.0, 87.0, 18.0 ],
					"text" : "j.remote eq2-freq"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.658824, 0.658824, 0.721569, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "" ],
					"patching_rect" : [ 564.0, 629.0, 79.0, 18.0 ],
					"text" : "j.remote eq1-lvl"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.658824, 0.658824, 0.721569, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-7",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "" ],
					"patching_rect" : [ 564.0, 408.0, 87.0, 18.0 ],
					"text" : "j.remote eq1-freq"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.658824, 0.658824, 0.721569, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "" ],
					"patching_rect" : [ 853.0, 572.0, 63.0, 18.0 ],
					"text" : "j.remote bal"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.658824, 0.658824, 0.721569, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-5",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "" ],
					"patching_rect" : [ 253.078064, 418.0, 59.5, 18.0 ],
					"text" : "j.remote lfx"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.658824, 0.658824, 0.721569, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "" ],
					"patching_rect" : [ 68.0, 419.0, 87.0, 18.0 ],
					"text" : "j.remote #1_indel"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.658824, 0.658824, 0.721569, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "" ],
					"patching_rect" : [ 382.770752, 418.0, 88.0, 18.0 ],
					"text" : "j.remote damping"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "live.meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "list" ],
					"patching_rect" : [ 367.385376, 536.5, 5.0, 42.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 410.0, 37.0, 8.0, 93.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "live.meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "list" ],
					"patching_rect" : [ 342.385376, 511.5, 5.0, 42.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 400.0, 37.0, 8.0, 93.0 ]
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.905882, 0.517647, 0.227451, 0.82 ],
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-21",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "signal", "", "" ],
					"patching_rect" : [ 360.385376, 508.0, 108.0, 18.0 ],
					"text" : "j.receive~ audio/out.R"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.905882, 0.517647, 0.227451, 0.82 ],
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-23",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "signal", "", "" ],
					"patching_rect" : [ 335.385376, 483.0, 106.0, 18.0 ],
					"text" : "j.receive~ audio/out.L"
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-9",
					"maxclass" : "outlet",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 13.0, 227.0, 25.0, 25.0 ]
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-8",
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 13.0, 160.0, 25.0, 25.0 ]
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.619608, 0.0, 0.360784, 0.698039 ],
					"fontname" : "Arial",
					"fontsize" : 10.0,
					"id" : "obj-3",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 13.0, 196.0, 36.0, 18.0 ],
					"text" : "j.view"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"bordercolor" : [ 0.649214, 0.672597, 0.655739, 1.0 ],
					"headercolor" : [ 0.321569, 0.521569, 0.584314, 1.0 ],
					"id" : "obj-1",
					"maxclass" : "j.ui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 0.0, 0.0, 300.0, 140.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 0.0, 0.0, 450.0, 210.0 ],
					"text" : "/vrb",
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 573.5, 660.0, 549.0, 660.0, 549.0, 489.0, 573.5, 489.0 ],
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-29", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 706.5, 658.0, 682.0, 658.0, 682.0, 490.0, 706.5, 490.0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 693.5, 434.0, 677.0, 434.0, 677.0, 339.0, 693.5, 339.0 ],
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 262.578064, 325.0, 240.0, 325.0, 240.0, 224.0, 262.578064, 224.0 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-20", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 383.578064, 321.5, 360.0, 321.5, 360.0, 225.5, 383.578064, 225.5 ],
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 392.270752, 443.0, 368.692688, 443.0, 368.692688, 345.0, 392.270752, 345.0 ],
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 77.5, 447.0, 53.0, 447.0, 53.0, 290.0, 77.5, 290.0 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 262.578064, 448.0, 239.692688, 448.0, 239.692688, 345.0, 262.578064, 345.0 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 862.5, 600.0, 840.0, 600.0, 840.0, 506.0, 862.5, 506.0 ],
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 573.5, 435.0, 549.0, 435.0, 549.0, 334.0, 573.5, 334.0 ],
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-8", 0 ]
				}

			}
 ]
	}

}
