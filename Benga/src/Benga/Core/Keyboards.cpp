#include "bgpch.h"
#include "Keyboards.h"

namespace Benga {

	std::unordered_map<KeyCode, int> QWERTYKeyboard::m_KeyCodeToglfw = {

		// From glfw3.h -> QWERTY Layout
		{ KeyCode::Space				, 32	},
		{ KeyCode::Apostrophe			, 39	}, /* ' */
		{ KeyCode::Comma				, 44	}, /* }, */
		{ KeyCode::Minus				, 45	}, /* - */
		{ KeyCode::Period				, 46	}, /* . */
		{ KeyCode::Slash				, 47	}, /* / */

		{ KeyCode::D0					, 48	}, /* 0 */
		{ KeyCode::D1					, 49	}, /* 1 */
		{ KeyCode::D2					, 50	}, /* 2 */
		{ KeyCode::D3					, 51	}, /* 3 */
		{ KeyCode::D4					, 52	}, /* 4 */
		{ KeyCode::D5					, 53	}, /* 5 */
		{ KeyCode::D6					, 54	}, /* 6 */
		{ KeyCode::D7					, 55	}, /* 7 */
		{ KeyCode::D8					, 56	}, /* 8 */
		{ KeyCode::D9					, 57	}, /* 9 */

		{ KeyCode::Semicolon			, 59	}, /* ; */
		{ KeyCode::Equal				, 61	}, /* , */

		{ KeyCode::A					, 65	},
		{ KeyCode::B					, 66	},
		{ KeyCode::C					, 67	},
		{ KeyCode::D					, 68	},
		{ KeyCode::E					, 69	},
		{ KeyCode::F					, 70	},
		{ KeyCode::G					, 71	},
		{ KeyCode::H					, 72	},
		{ KeyCode::I					, 73	},
		{ KeyCode::J					, 74	},
		{ KeyCode::K					, 75	},
		{ KeyCode::L					, 76	},
		{ KeyCode::M					, 77	},
		{ KeyCode::N					, 78	},
		{ KeyCode::O					, 79	},
		{ KeyCode::P					, 80	},
		{ KeyCode::Q					, 81	},
		{ KeyCode::R					, 82	},
		{ KeyCode::S					, 83	},
		{ KeyCode::T					, 84	},
		{ KeyCode::U					, 85	},
		{ KeyCode::V					, 86	},
		{ KeyCode::W					, 87	},
		{ KeyCode::X					, 88	},
		{ KeyCode::Y					, 89	},
		{ KeyCode::Z					, 90	},

		{ KeyCode::LeftBracket			, 91	},  /* [ */
		{ KeyCode::Backslash			, 92	},  /* \ */
		{ KeyCode::RightBracket			, 93	},  /* ] */
		{ KeyCode::GraveAccent			, 96	},  /* ` */

		{ KeyCode::World1				, 161	}, /* non-US #1 */
		{ KeyCode::World2				, 162	}, /* non-US #2 */
											
		/* Function keys*/					
		{ KeyCode::Escape				, 256	},
		{ KeyCode::Enter				, 257	},
		{ KeyCode::Tab					, 258	},
		{ KeyCode::Backspace			, 259	},
		{ KeyCode::Insert				, 260	},
		{ KeyCode::Delete				, 261	},
		{ KeyCode::Right				, 262	},
		{ KeyCode::Left					, 263	},
		{ KeyCode::Down					, 264	},
		{ KeyCode::Up					, 265	},
		{ KeyCode::PageUp				, 266	},
		{ KeyCode::PageDown				, 267	},
		{ KeyCode::Home					, 268	},
		{ KeyCode::End					, 269	},
		{ KeyCode::CapsLock				, 280	},
		{ KeyCode::ScrollLock			, 281	},
		{ KeyCode::NumLock				, 282	},
		{ KeyCode::PrintScreen			, 283	},
		{ KeyCode::Pause				, 284	},
		{ KeyCode::F1					, 290	},
		{ KeyCode::F2					, 291	},
		{ KeyCode::F3					, 292	},
		{ KeyCode::F4					, 293	},
		{ KeyCode::F5					, 294	},
		{ KeyCode::F6					, 295	},
		{ KeyCode::F7					, 296	},
		{ KeyCode::F8					, 297	},
		{ KeyCode::F9					, 298	},
		{ KeyCode::F10					, 299	},
		{ KeyCode::F11					, 300	},
		{ KeyCode::F12					, 301	},
		{ KeyCode::F13					, 302	},
		{ KeyCode::F14					, 303	},
		{ KeyCode::F15					, 304	},
		{ KeyCode::F16					, 305	},
		{ KeyCode::F17					, 306	},
		{ KeyCode::F18					, 307	},
		{ KeyCode::F19					, 308	},
		{ KeyCode::F20					, 309	},
		{ KeyCode::F21					, 310	},
		{ KeyCode::F22					, 311	},
		{ KeyCode::F23					, 312	},
		{ KeyCode::F24					, 313	},
		{ KeyCode::F25					, 314	},
											
		/* Keypad */						
		{ KeyCode::KP0					, 320	},
		{ KeyCode::KP1					, 321	},
		{ KeyCode::KP2					, 322	},
		{ KeyCode::KP3					, 323	},
		{ KeyCode::KP4					, 324	},
		{ KeyCode::KP5					, 325	},
		{ KeyCode::KP6					, 326	},
		{ KeyCode::KP7					, 327	},
		{ KeyCode::KP8					, 328	},
		{ KeyCode::KP9					, 329	},
		{ KeyCode::KPDecimal			, 330	},
		{ KeyCode::KPDivide				, 331	},
		{ KeyCode::KPMultiply			, 332	},
		{ KeyCode::KPSubtract			, 333	},
		{ KeyCode::KPAdd				, 334	},
		{ KeyCode::KPEnter				, 335	},
		{ KeyCode::KPEqual				, 336	},
		{ KeyCode::LeftShift			, 340	},
		{ KeyCode::LeftControl			, 341	},
		{ KeyCode::LeftAlt				, 342	},
		{ KeyCode::LeftSuper			, 343	},
		{ KeyCode::RightShift			, 344	},
		{ KeyCode::RightControl			, 345	},
		{ KeyCode::RightAlt				, 346	},
		{ KeyCode::RightSuper			, 347	},
		{ KeyCode::Menu					, 348	},
	};
	
	std::unordered_map<int, KeyCode> QWERTYKeyboard::m_glfwToKeyCode = {
		
		// From glfw3.h -> QWERTY Layout
		{ 32	, KeyCode::Space			},
		{ 39	, KeyCode::Apostrophe		}, /* ' */
		{ 44	, KeyCode::Comma			}, /* }, */
		{ 45	, KeyCode::Minus			}, /* - */
		{ 46	, KeyCode::Period			}, /* . */
		{ 47	, KeyCode::Slash			}, /* / */

		{ 48	, KeyCode::D0				}, /* 0 */
		{ 49	, KeyCode::D1				}, /* 1 */
		{ 50	, KeyCode::D2				}, /* 2 */
		{ 51	, KeyCode::D3				}, /* 3 */
		{ 52	, KeyCode::D4				}, /* 4 */
		{ 53	, KeyCode::D5				}, /* 5 */
		{ 54	, KeyCode::D6				}, /* 6 */
		{ 55	, KeyCode::D7				}, /* 7 */
		{ 56	, KeyCode::D8				}, /* 8 */
		{ 57	, KeyCode::D9				}, /* 9 */

		{ 59	, KeyCode::Semicolon		}, /* ; */
		{ 61	, KeyCode::Equal			}, /* , */

		{ 65	, KeyCode::A				},
		{ 66	, KeyCode::B				},
		{ 67	, KeyCode::C				},
		{ 68	, KeyCode::D				},
		{ 69	, KeyCode::E				},
		{ 70	, KeyCode::F				},
		{ 71	, KeyCode::G				},
		{ 72	, KeyCode::H				},
		{ 73	, KeyCode::I				},
		{ 74	, KeyCode::J				},
		{ 75	, KeyCode::K				},
		{ 76	, KeyCode::L				},
		{ 77	, KeyCode::M				},
		{ 78	, KeyCode::N				},
		{ 79	, KeyCode::O				},
		{ 80	, KeyCode::P				},
		{ 81	, KeyCode::Q				},
		{ 82	, KeyCode::R				},
		{ 83	, KeyCode::S				},
		{ 84	, KeyCode::T				},
		{ 85	, KeyCode::U				},
		{ 86	, KeyCode::V				},
		{ 87	, KeyCode::W				},
		{ 88	, KeyCode::X				},
		{ 89	, KeyCode::Y				},
		{ 90	, KeyCode::Z				},

		{ 91	, KeyCode::LeftBracket		},  /* [ */
		{ 92	, KeyCode::Backslash		},  /* \ */
		{ 93	, KeyCode::RightBracket		},  /* ] */
		{ 96	, KeyCode::GraveAccent		},  /* ` */

		{ 161	, KeyCode::World1			}, /* non-US #1 */
		{ 162	, KeyCode::World2			}, /* non-US #2 */

		/* Function keys*/
		{ 256	, KeyCode::Escape			},
		{ 257	, KeyCode::Enter			},
		{ 258	, KeyCode::Tab				},
		{ 259	, KeyCode::Backspace		},
		{ 260	, KeyCode::Insert			},
		{ 261	, KeyCode::Delete			},
		{ 262	, KeyCode::Right			},
		{ 263	, KeyCode::Left				},
		{ 264	, KeyCode::Down				},
		{ 265	, KeyCode::Up				},
		{ 266	, KeyCode::PageUp			},
		{ 267	, KeyCode::PageDown			},
		{ 268	, KeyCode::Home				},
		{ 269	, KeyCode::End				},
		{ 280	, KeyCode::CapsLock			},
		{ 281	, KeyCode::ScrollLock		},
		{ 282	, KeyCode::NumLock			},
		{ 283	, KeyCode::PrintScreen		},
		{ 284	, KeyCode::Pause			},
		{ 290	, KeyCode::F1				},
		{ 291	, KeyCode::F2				},
		{ 292	, KeyCode::F3				},
		{ 293	, KeyCode::F4				},
		{ 294	, KeyCode::F5				},
		{ 295	, KeyCode::F6				},
		{ 296	, KeyCode::F7				},
		{ 297	, KeyCode::F8				},
		{ 298	, KeyCode::F9				},
		{ 299	, KeyCode::F10				},
		{ 300	, KeyCode::F11				},
		{ 301	, KeyCode::F12				},
		{ 302	, KeyCode::F13				},
		{ 303	, KeyCode::F14				},
		{ 304	, KeyCode::F15				},
		{ 305	, KeyCode::F16				},
		{ 306	, KeyCode::F17				},
		{ 307	, KeyCode::F18				},
		{ 308	, KeyCode::F19				},
		{ 309	, KeyCode::F20				},
		{ 310	, KeyCode::F21				},
		{ 311	, KeyCode::F22				},
		{ 312	, KeyCode::F23				},
		{ 313	, KeyCode::F24				},
		{ 314	, KeyCode::F25				},

		/* Keypad */
		{ 320	, KeyCode::KP0				},
		{ 321	, KeyCode::KP1				},
		{ 322	, KeyCode::KP2				},
		{ 323	, KeyCode::KP3				},
		{ 324	, KeyCode::KP4				},
		{ 325	, KeyCode::KP5				},
		{ 326	, KeyCode::KP6				},
		{ 327	, KeyCode::KP7				},
		{ 328	, KeyCode::KP8				},
		{ 329	, KeyCode::KP9				},
		{ 330	, KeyCode::KPDecimal		},
		{ 331	, KeyCode::KPDivide			},
		{ 332	, KeyCode::KPMultiply		},
		{ 333	, KeyCode::KPSubtract		},
		{ 334	, KeyCode::KPAdd			},
		{ 335	, KeyCode::KPEnter			},
		{ 336	, KeyCode::KPEqual			},
		{ 340	, KeyCode::LeftShift		},
		{ 341	, KeyCode::LeftControl		},
		{ 342	, KeyCode::LeftAlt			},
		{ 343	, KeyCode::LeftSuper		},
		{ 344	, KeyCode::RightShift		},
		{ 345	, KeyCode::RightControl		},
		{ 346	, KeyCode::RightAlt			},
		{ 347	, KeyCode::RightSuper		},
		{ 348	, KeyCode::Menu				},
	};
	
	std::unordered_map<KeyCode, int> BelgianPeriodKeyboard::m_KeyCodeToglfw = {

		// From glfw3.h -> QWERTY Layout (wrong)
		{ KeyCode::Space				, 32	},
		{ KeyCode::Apostrophe			, 39	}, /* ' */
		{ KeyCode::Comma				, 44	}, /* }, */
		{ KeyCode::Minus				, 45	}, /* - */
		{ KeyCode::Period				, 46	}, /* . */
		{ KeyCode::Slash				, 47	}, /* / */

		{ KeyCode::D0					, 48	}, /* 0 */
		{ KeyCode::D1					, 49	}, /* 1 */
		{ KeyCode::D2					, 50	}, /* 2 */
		{ KeyCode::D3					, 51	}, /* 3 */
		{ KeyCode::D4					, 52	}, /* 4 */
		{ KeyCode::D5					, 53	}, /* 5 */
		{ KeyCode::D6					, 54	}, /* 6 */
		{ KeyCode::D7					, 55	}, /* 7 */
		{ KeyCode::D8					, 56	}, /* 8 */
		{ KeyCode::D9					, 57	}, /* 9 */

		{ KeyCode::Semicolon			, 59	}, /* ; */
		{ KeyCode::Equal				, 61	}, /* , */

		{ KeyCode::A					, 65	},
		{ KeyCode::B					, 66	},
		{ KeyCode::C					, 67	},
		{ KeyCode::D					, 68	},
		{ KeyCode::E					, 69	},
		{ KeyCode::F					, 70	},
		{ KeyCode::G					, 71	},
		{ KeyCode::H					, 72	},
		{ KeyCode::I					, 73	},
		{ KeyCode::J					, 74	},
		{ KeyCode::K					, 75	},
		{ KeyCode::L					, 76	},
		{ KeyCode::M					, 77	},
		{ KeyCode::N					, 78	},
		{ KeyCode::O					, 79	},
		{ KeyCode::P					, 80	},
		{ KeyCode::Q					, 81	},
		{ KeyCode::R					, 82	},
		{ KeyCode::S					, 83	},
		{ KeyCode::T					, 84	},
		{ KeyCode::U					, 85	},
		{ KeyCode::V					, 86	},
		{ KeyCode::W					, 87	},
		{ KeyCode::X					, 88	},
		{ KeyCode::Y					, 89	},
		{ KeyCode::Z					, 90	},

		{ KeyCode::LeftBracket			, 91	},  /* [ */
		{ KeyCode::Backslash			, 92	},  /* \ */
		{ KeyCode::RightBracket			, 93	},  /* ] */
		{ KeyCode::GraveAccent			, 96	},  /* ` */

		{ KeyCode::World1				, 161	}, /* non-US #1 */
		{ KeyCode::World2				, 162	}, /* non-US #2 */

		/* Function keys*/
		{ KeyCode::Escape				, 256	},
		{ KeyCode::Enter				, 257	},
		{ KeyCode::Tab					, 258	},
		{ KeyCode::Backspace			, 259	},
		{ KeyCode::Insert				, 260	},
		{ KeyCode::Delete				, 261	},
		{ KeyCode::Right				, 262	},
		{ KeyCode::Left					, 263	},
		{ KeyCode::Down					, 264	},
		{ KeyCode::Up					, 265	},
		{ KeyCode::PageUp				, 266	},
		{ KeyCode::PageDown				, 267	},
		{ KeyCode::Home					, 268	},
		{ KeyCode::End					, 269	},
		{ KeyCode::CapsLock				, 280	},
		{ KeyCode::ScrollLock			, 281	},
		{ KeyCode::NumLock				, 282	},
		{ KeyCode::PrintScreen			, 283	},
		{ KeyCode::Pause				, 284	},
		{ KeyCode::F1					, 290	},
		{ KeyCode::F2					, 291	},
		{ KeyCode::F3					, 292	},
		{ KeyCode::F4					, 293	},
		{ KeyCode::F5					, 294	},
		{ KeyCode::F6					, 295	},
		{ KeyCode::F7					, 296	},
		{ KeyCode::F8					, 297	},
		{ KeyCode::F9					, 298	},
		{ KeyCode::F10					, 299	},
		{ KeyCode::F11					, 300	},
		{ KeyCode::F12					, 301	},
		{ KeyCode::F13					, 302	},
		{ KeyCode::F14					, 303	},
		{ KeyCode::F15					, 304	},
		{ KeyCode::F16					, 305	},
		{ KeyCode::F17					, 306	},
		{ KeyCode::F18					, 307	},
		{ KeyCode::F19					, 308	},
		{ KeyCode::F20					, 309	},
		{ KeyCode::F21					, 310	},
		{ KeyCode::F22					, 311	},
		{ KeyCode::F23					, 312	},
		{ KeyCode::F24					, 313	},
		{ KeyCode::F25					, 314	},

		/* Keypad */
		{ KeyCode::KP0					, 320	},
		{ KeyCode::KP1					, 321	},
		{ KeyCode::KP2					, 322	},
		{ KeyCode::KP3					, 323	},
		{ KeyCode::KP4					, 324	},
		{ KeyCode::KP5					, 325	},
		{ KeyCode::KP6					, 326	},
		{ KeyCode::KP7					, 327	},
		{ KeyCode::KP8					, 328	},
		{ KeyCode::KP9					, 329	},
		{ KeyCode::KPDecimal			, 330	},
		{ KeyCode::KPDivide				, 331	},
		{ KeyCode::KPMultiply			, 332	},
		{ KeyCode::KPSubtract			, 333	},
		{ KeyCode::KPAdd				, 334	},
		{ KeyCode::KPEnter				, 335	},
		{ KeyCode::KPEqual				, 336	},
		{ KeyCode::LeftShift			, 340	},
		{ KeyCode::LeftControl			, 341	},
		{ KeyCode::LeftAlt				, 342	},
		{ KeyCode::LeftSuper			, 343	},
		{ KeyCode::RightShift			, 344	},
		{ KeyCode::RightControl			, 345	},
		{ KeyCode::RightAlt				, 346	},
		{ KeyCode::RightSuper			, 347	},
		{ KeyCode::Menu					, 348	},
	};
	
	std::unordered_map<int, KeyCode> BelgianPeriodKeyboard::m_glfwToKeyCode = {

		// From glfw3.h -> QWERTY Layout (wrong)
		{ 32	, KeyCode::Space			},
		{ 39	, KeyCode::Apostrophe		}, /* ' */
		{ 44	, KeyCode::Comma			}, /* }, */
		{ 45	, KeyCode::Minus			}, /* - */
		{ 46	, KeyCode::Period			}, /* . */
		{ 47	, KeyCode::Slash			}, /* / */

		{ 48	, KeyCode::D0				}, /* 0 */
		{ 49	, KeyCode::D1				}, /* 1 */
		{ 50	, KeyCode::D2				}, /* 2 */
		{ 51	, KeyCode::D3				}, /* 3 */
		{ 52	, KeyCode::D4				}, /* 4 */
		{ 53	, KeyCode::D5				}, /* 5 */
		{ 54	, KeyCode::D6				}, /* 6 */
		{ 55	, KeyCode::D7				}, /* 7 */
		{ 56	, KeyCode::D8				}, /* 8 */
		{ 57	, KeyCode::D9				}, /* 9 */

		{ 59	, KeyCode::Semicolon		}, /* ; */
		{ 61	, KeyCode::Equal			}, /* , */

		{ 65	, KeyCode::A				},
		{ 66	, KeyCode::B				},
		{ 67	, KeyCode::C				},
		{ 68	, KeyCode::D				},
		{ 69	, KeyCode::E				},
		{ 70	, KeyCode::F				},
		{ 71	, KeyCode::G				},
		{ 72	, KeyCode::H				},
		{ 73	, KeyCode::I				},
		{ 74	, KeyCode::J				},
		{ 75	, KeyCode::K				},
		{ 76	, KeyCode::L				},
		{ 77	, KeyCode::M				},
		{ 78	, KeyCode::N				},
		{ 79	, KeyCode::O				},
		{ 80	, KeyCode::P				},
		{ 81	, KeyCode::Q				},
		{ 82	, KeyCode::R				},
		{ 83	, KeyCode::S				},
		{ 84	, KeyCode::T				},
		{ 85	, KeyCode::U				},
		{ 86	, KeyCode::V				},
		{ 87	, KeyCode::W				},
		{ 88	, KeyCode::X				},
		{ 89	, KeyCode::Y				},
		{ 90	, KeyCode::Z				},

		{ 91	, KeyCode::LeftBracket		},  /* [ */
		{ 92	, KeyCode::Backslash		},  /* \ */
		{ 93	, KeyCode::RightBracket		},  /* ] */
		{ 96	, KeyCode::GraveAccent		},  /* ` */

		{ 161	, KeyCode::World1			}, /* non-US #1 */
		{ 162	, KeyCode::World2			}, /* non-US #2 */

		/* Function keys*/
		{ 256	, KeyCode::Escape			},
		{ 257	, KeyCode::Enter			},
		{ 258	, KeyCode::Tab				},
		{ 259	, KeyCode::Backspace		},
		{ 260	, KeyCode::Insert			},
		{ 261	, KeyCode::Delete			},
		{ 262	, KeyCode::Right			},
		{ 263	, KeyCode::Left				},
		{ 264	, KeyCode::Down				},
		{ 265	, KeyCode::Up				},
		{ 266	, KeyCode::PageUp			},
		{ 267	, KeyCode::PageDown			},
		{ 268	, KeyCode::Home				},
		{ 269	, KeyCode::End				},
		{ 280	, KeyCode::CapsLock			},
		{ 281	, KeyCode::ScrollLock		},
		{ 282	, KeyCode::NumLock			},
		{ 283	, KeyCode::PrintScreen		},
		{ 284	, KeyCode::Pause			},
		{ 290	, KeyCode::F1				},
		{ 291	, KeyCode::F2				},
		{ 292	, KeyCode::F3				},
		{ 293	, KeyCode::F4				},
		{ 294	, KeyCode::F5				},
		{ 295	, KeyCode::F6				},
		{ 296	, KeyCode::F7				},
		{ 297	, KeyCode::F8				},
		{ 298	, KeyCode::F9				},
		{ 299	, KeyCode::F10				},
		{ 300	, KeyCode::F11				},
		{ 301	, KeyCode::F12				},
		{ 302	, KeyCode::F13				},
		{ 303	, KeyCode::F14				},
		{ 304	, KeyCode::F15				},
		{ 305	, KeyCode::F16				},
		{ 306	, KeyCode::F17				},
		{ 307	, KeyCode::F18				},
		{ 308	, KeyCode::F19				},
		{ 309	, KeyCode::F20				},
		{ 310	, KeyCode::F21				},
		{ 311	, KeyCode::F22				},
		{ 312	, KeyCode::F23				},
		{ 313	, KeyCode::F24				},
		{ 314	, KeyCode::F25				},

		/* Keypad */
		{ 320	, KeyCode::KP0				},
		{ 321	, KeyCode::KP1				},
		{ 322	, KeyCode::KP2				},
		{ 323	, KeyCode::KP3				},
		{ 324	, KeyCode::KP4				},
		{ 325	, KeyCode::KP5				},
		{ 326	, KeyCode::KP6				},
		{ 327	, KeyCode::KP7				},
		{ 328	, KeyCode::KP8				},
		{ 329	, KeyCode::KP9				},
		{ 330	, KeyCode::KPDecimal		},
		{ 331	, KeyCode::KPDivide			},
		{ 332	, KeyCode::KPMultiply		},
		{ 333	, KeyCode::KPSubtract		},
		{ 334	, KeyCode::KPAdd			},
		{ 335	, KeyCode::KPEnter			},
		{ 336	, KeyCode::KPEqual			},
		{ 340	, KeyCode::LeftShift		},
		{ 341	, KeyCode::LeftControl		},
		{ 342	, KeyCode::LeftAlt			},
		{ 343	, KeyCode::LeftSuper		},
		{ 344	, KeyCode::RightShift		},
		{ 345	, KeyCode::RightControl		},
		{ 346	, KeyCode::RightAlt			},
		{ 347	, KeyCode::RightSuper		},
		{ 348	, KeyCode::Menu				},
	};
}
