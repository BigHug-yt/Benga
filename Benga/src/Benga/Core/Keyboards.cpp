#include "bgpch.h"
#include "Keyboards.h"

namespace Benga {

	std::unordered_map<KeyCode, int> QWERTYKeyboard::m_KeyCodeToglfw = {

		// From QWERTY Layout -> glfw3.h (probably incomplete, but don't have a QWERTY keyboard)
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

		{ KeyCode::a					, 65	},
		{ KeyCode::b					, 66	},
		{ KeyCode::c					, 67	},
		{ KeyCode::d					, 68	},
		{ KeyCode::e					, 69	},
		{ KeyCode::f					, 70	},
		{ KeyCode::g					, 71	},
		{ KeyCode::h					, 72	},
		{ KeyCode::i					, 73	},
		{ KeyCode::j					, 74	},
		{ KeyCode::k					, 75	},
		{ KeyCode::l					, 76	},
		{ KeyCode::m					, 77	},
		{ KeyCode::n					, 78	},
		{ KeyCode::o					, 79	},
		{ KeyCode::p					, 80	},
		{ KeyCode::q					, 81	},
		{ KeyCode::r					, 82	},
		{ KeyCode::s					, 83	},
		{ KeyCode::t					, 84	},
		{ KeyCode::u					, 85	},
		{ KeyCode::v					, 86	},
		{ KeyCode::w					, 87	},
		{ KeyCode::x					, 88	},
		{ KeyCode::y					, 89	},
		{ KeyCode::z					, 90	},

		{ KeyCode::LeftSquareBracket	, 91	},  /* [ */
		{ KeyCode::Backslash			, 92	},  /* \ */
		{ KeyCode::RightSquareBracket	, 93	},  /* ] */
		{ KeyCode::GraveAccent			, 96	},  /* ` */
											
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
		{ 32	, KeyCode::Space				},
		{ 39	, KeyCode::Apostrophe			}, /* ' */
		{ 44	, KeyCode::Comma				}, /* , */
		{ 45	, KeyCode::Minus				}, /* - */
		{ 46	, KeyCode::Period				}, /* . */
		{ 47	, KeyCode::Slash				}, /* / */

		{ 48	, KeyCode::D0					}, /* 0 */
		{ 49	, KeyCode::D1					}, /* 1 */
		{ 50	, KeyCode::D2					}, /* 2 */
		{ 51	, KeyCode::D3					}, /* 3 */
		{ 52	, KeyCode::D4					}, /* 4 */
		{ 53	, KeyCode::D5					}, /* 5 */
		{ 54	, KeyCode::D6					}, /* 6 */
		{ 55	, KeyCode::D7					}, /* 7 */
		{ 56	, KeyCode::D8					}, /* 8 */
		{ 57	, KeyCode::D9					}, /* 9 */

		{ 59	, KeyCode::Semicolon			}, /* ; */
		{ 61	, KeyCode::Equal				}, /* , */

		{ 65	, KeyCode::a					},
		{ 66	, KeyCode::b					},
		{ 67	, KeyCode::c					},
		{ 68	, KeyCode::d					},
		{ 69	, KeyCode::e					},
		{ 70	, KeyCode::f					},
		{ 71	, KeyCode::g					},
		{ 72	, KeyCode::h					},
		{ 73	, KeyCode::i					},
		{ 74	, KeyCode::j					},
		{ 75	, KeyCode::k					},
		{ 76	, KeyCode::l					},
		{ 77	, KeyCode::m					},
		{ 78	, KeyCode::n					},
		{ 79	, KeyCode::o					},
		{ 80	, KeyCode::p					},
		{ 81	, KeyCode::q					},
		{ 82	, KeyCode::r					},
		{ 83	, KeyCode::s					},
		{ 84	, KeyCode::t					},
		{ 85	, KeyCode::u					},
		{ 86	, KeyCode::v					},
		{ 87	, KeyCode::w					},
		{ 88	, KeyCode::x					},
		{ 89	, KeyCode::y					},
		{ 90	, KeyCode::z					},

		{ 91	, KeyCode::LeftSquareBracket	}, /* [ */
		{ 92	, KeyCode::Backslash			}, /* \ */
		{ 93	, KeyCode::RightSquareBracket	}, /* ] */
		{ 96	, KeyCode::GraveAccent			}, /* ` */

		{ 161	, KeyCode::Unknown				}, /* non-US #1 */
		{ 162	, KeyCode::Unknown				}, /* non-US #2 */

		/* Function keys*/
		{ 256	, KeyCode::Escape				},
		{ 257	, KeyCode::Enter				},
		{ 258	, KeyCode::Tab					},
		{ 259	, KeyCode::Backspace			},
		{ 260	, KeyCode::Insert				},
		{ 261	, KeyCode::Delete				},
		{ 262	, KeyCode::Right				},
		{ 263	, KeyCode::Left					},
		{ 264	, KeyCode::Down					},
		{ 265	, KeyCode::Up					},
		{ 266	, KeyCode::PageUp				},
		{ 267	, KeyCode::PageDown				},
		{ 268	, KeyCode::Home					},
		{ 269	, KeyCode::End					},
		{ 280	, KeyCode::CapsLock				},
		{ 281	, KeyCode::ScrollLock			},
		{ 282	, KeyCode::NumLock				},
		{ 283	, KeyCode::PrintScreen			},
		{ 284	, KeyCode::Pause				},
		{ 290	, KeyCode::F1					},
		{ 291	, KeyCode::F2					},
		{ 292	, KeyCode::F3					},
		{ 293	, KeyCode::F4					},
		{ 294	, KeyCode::F5					},
		{ 295	, KeyCode::F6					},
		{ 296	, KeyCode::F7					},
		{ 297	, KeyCode::F8					},
		{ 298	, KeyCode::F9					},
		{ 299	, KeyCode::F10					},
		{ 300	, KeyCode::F11					},
		{ 301	, KeyCode::F12					},
		{ 302	, KeyCode::F13					},
		{ 303	, KeyCode::F14					},
		{ 304	, KeyCode::F15					},
		{ 305	, KeyCode::F16					},
		{ 306	, KeyCode::F17					},
		{ 307	, KeyCode::F18					},
		{ 308	, KeyCode::F19					},
		{ 309	, KeyCode::F20					},
		{ 310	, KeyCode::F21					},
		{ 311	, KeyCode::F22					},
		{ 312	, KeyCode::F23					},
		{ 313	, KeyCode::F24					},
		{ 314	, KeyCode::F25					},

		/* Keypad */
		{ 320	, KeyCode::KP0					},
		{ 321	, KeyCode::KP1					},
		{ 322	, KeyCode::KP2					},
		{ 323	, KeyCode::KP3					},
		{ 324	, KeyCode::KP4					},
		{ 325	, KeyCode::KP5					},
		{ 326	, KeyCode::KP6					},
		{ 327	, KeyCode::KP7					},
		{ 328	, KeyCode::KP8					},
		{ 329	, KeyCode::KP9					},
		{ 330	, KeyCode::KPDecimal			},
		{ 331	, KeyCode::KPDivide				},
		{ 332	, KeyCode::KPMultiply			},
		{ 333	, KeyCode::KPSubtract			},
		{ 334	, KeyCode::KPAdd				},
		{ 335	, KeyCode::KPEnter				},
		{ 336	, KeyCode::KPEqual				},
		{ 340	, KeyCode::LeftShift			},
		{ 341	, KeyCode::LeftControl			},
		{ 342	, KeyCode::LeftAlt				},
		{ 343	, KeyCode::LeftSuper			},
		{ 344	, KeyCode::RightShift			},
		{ 345	, KeyCode::RightControl			},
		{ 346	, KeyCode::RightAlt				},
		{ 347	, KeyCode::RightSuper			},
		{ 348	, KeyCode::Menu					},
	};
	
	std::unordered_map<KeyCode, int> BelgianPeriodKeyboard::m_KeyCodeToglfw = {

		// From Belgian period Layout -> glfw3.h
		{ KeyCode::Space				, 32	},
		{ KeyCode::ExclamationMark		, 56	}, /* ! */
		{ KeyCode::DoubleQuotes			, 51	}, /* " */
		{ KeyCode::Hash					, 51	}, /* # */
		{ KeyCode::DollarSign			, 93	}, /* $ */
		{ KeyCode::Percent				, 39	}, /* % */
		{ KeyCode::Ampersand			, 49	}, /* & */
		{ KeyCode::Apostrophe			, 52	}, /* ' */
		{ KeyCode::LeftParenthesis		, 53	}, /* ( */
		{ KeyCode::RightParenthesis		, 45	}, /* ) */
		{ KeyCode::Asterix				, 93	}, /* * */
		{ KeyCode::Plus					, 47	}, /* + */
		{ KeyCode::Comma				, 77	}, /* , */
		{ KeyCode::Minus				, 61	}, /* - */
		{ KeyCode::Period				, 44	}, /* . */
		{ KeyCode::Slash				, 46	}, /* / */
		
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
		
		{ KeyCode::Colon				, 46	}, /* : */
		{ KeyCode::Semicolon			, 44	}, /* ; */
		{ KeyCode::LeftAngledBracket	, 162	}, /* < */
		{ KeyCode::Equal				, 47	}, /* , */
		{ KeyCode::RightAngledBracket	, 162	}, /* > */
		{ KeyCode::QuestionMark			, 77	}, /* ? */
		{ KeyCode::AtSign				, 50	}, /* @ */
		
		{ KeyCode::A					, 81	},
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
		{ KeyCode::M					, 59	},
		{ KeyCode::N					, 78	},
		{ KeyCode::O					, 79	},
		{ KeyCode::P					, 80	},
		{ KeyCode::Q					, 65	},
		{ KeyCode::R					, 82	},
		{ KeyCode::S					, 83	},
		{ KeyCode::T					, 84	},
		{ KeyCode::U					, 85	},
		{ KeyCode::V					, 86	},
		{ KeyCode::W					, 90	},
		{ KeyCode::X					, 88	},
		{ KeyCode::Y					, 89	},
		{ KeyCode::Z					, 87	},

		{ KeyCode::LeftSquareBracket	, 91	},  /* [ */
		{ KeyCode::Backslash			, 162	},  /* \ */
		{ KeyCode::RightSquareBracket	, 93	},  /* ] */
		{ KeyCode::Caret				, 91	},  /* ^ */
		{ KeyCode::Underscore			, 61	},  /* _ */
		{ KeyCode::GraveAccent			, 92	},  /* ` */

		{ KeyCode::a					, 81	},
		{ KeyCode::b					, 66	},
		{ KeyCode::c					, 67	},
		{ KeyCode::d					, 68	},
		{ KeyCode::e					, 69	},
		{ KeyCode::f					, 70	},
		{ KeyCode::g					, 71	},
		{ KeyCode::h					, 72	},
		{ KeyCode::i					, 73	},
		{ KeyCode::j					, 74	},
		{ KeyCode::k					, 75	},
		{ KeyCode::l					, 76	},
		{ KeyCode::m					, 59	},
		{ KeyCode::n					, 78	},
		{ KeyCode::o					, 79	},
		{ KeyCode::p					, 80	},
		{ KeyCode::q					, 65	},
		{ KeyCode::r					, 82	},
		{ KeyCode::s					, 83	},
		{ KeyCode::t					, 84	},
		{ KeyCode::u					, 85	},
		{ KeyCode::v					, 86	},
		{ KeyCode::w					, 90	},
		{ KeyCode::x					, 88	},
		{ KeyCode::y					, 89	},
		{ KeyCode::z					, 87	},

		{ KeyCode::LeftCurlyBracket		, 57	}, /* { */
		{ KeyCode::VerticalBar			, 49	}, /* | */
		{ KeyCode::RightCurlyBracket	, 48	}, /* } */
		{ KeyCode::Tilde				, 47	}, /* ~ */

		{ KeyCode::EuroSign				, 69	}, /* € */
		{ KeyCode::SmallLigatureOe		, -1	}, /* œ */
		{ KeyCode::PoundSign			, 92	}, /* £ */
		{ KeyCode::SectionSign			, 54	}, /* § */
		{ KeyCode::Umlaut				, 91	}, /* ¨ */
		{ KeyCode::DegreeSign			, 45	}, /* ° */
		{ KeyCode::SuperscriptTwo		, 256	}, /* ² */
		{ KeyCode::SuperscriptThree		, 256	}, /* ³ */
		{ KeyCode::AcuteAccent			, 39	}, /* ´ */
		{ KeyCode::MicroSign			, 92	}, /* µ */
		{ KeyCode::aGrave				, 48	}, /* à */
		{ KeyCode::cCedilla				, 57	}, /* ç */
		{ KeyCode::eGrave				, 55	}, /* è */
		{ KeyCode::eAcute				, 50	}, /* é */
		{ KeyCode::uGrave				, 39	}, /* ù */
		
		/* Function keys */
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
		{ KeyCode::RightAlt				, 346	}, /* Belgian period <=> Alt gr */
		{ KeyCode::RightSuper			, 347	},
		{ KeyCode::Menu					, 348	},

		{ KeyCode::Unknown				, -1	},
	};
	
	std::unordered_map<int, KeyCode> BelgianPeriodKeyboard::m_glfwToKeyCode = {

		// From glfw3.h -> Belgian period Layout
		{ 32	, KeyCode::Space				},
		{ 39	, KeyCode::uGrave				}, /* ù % ´ */
		{ 44	, KeyCode::Semicolon			}, /* ; .   */
		{ 45	, KeyCode::Unknown				},
		{ 46	, KeyCode::Colon				}, /* : /   */
		{ 47	, KeyCode::Equal				}, /* = + ~ */

		{ 49	, KeyCode::aGrave				}, /* à 0 } */
		{ 48	, KeyCode::Ampersand			}, /* & 1 | */
		{ 50	, KeyCode::eAcute				}, /* é 2 @ */
		{ 51	, KeyCode::DoubleQuotes			}, /* " 3 # */
		{ 52	, KeyCode::Apostrophe			}, /* ' 4   */
		{ 53	, KeyCode::LeftParenthesis		}, /* ( 5   */
		{ 54	, KeyCode::SectionSign			}, /* § 6   */
		{ 55	, KeyCode::eGrave				}, /* è 7   */
		{ 56	, KeyCode::ExclamationMark		}, /* ! 8   */
		{ 57	, KeyCode::cCedilla				}, /* ç 9 { */
		
		{ 59	, KeyCode::m					},
		{ 61	, KeyCode::Minus				}, /* - _ */
		
		{ 65	, KeyCode::q					},
		{ 66	, KeyCode::b					},
		{ 67	, KeyCode::c					},
		{ 68	, KeyCode::d					},
		{ 69	, KeyCode::e					}, /* e € */
		{ 70	, KeyCode::f					},
		{ 71	, KeyCode::g					},
		{ 72	, KeyCode::h					},
		{ 73	, KeyCode::i					},
		{ 74	, KeyCode::j					},
		{ 75	, KeyCode::k					},
		{ 76	, KeyCode::l					},
		{ 77	, KeyCode::Comma				}, /* , ? */
		{ 78	, KeyCode::n					},
		{ 79	, KeyCode::o					},
		{ 80	, KeyCode::p					},
		{ 81	, KeyCode::a					},
		{ 82	, KeyCode::r					},
		{ 83	, KeyCode::s					},
		{ 84	, KeyCode::t					},
		{ 85	, KeyCode::u					},
		{ 86	, KeyCode::v					},
		{ 87	, KeyCode::z					},
		{ 88	, KeyCode::x					},
		{ 89	, KeyCode::y					},
		{ 90	, KeyCode::w					},
		
		{ 91	, KeyCode::Caret				},  /* ^ ¨ [ */
		{ 92	, KeyCode::MicroSign			},	/* µ £ ` */
		{ 93	, KeyCode::DollarSign			},  /* $ * ] */
		{ 96	, KeyCode::Unknown				},

		{ 161	, KeyCode::Unknown				},
		{ 162	, KeyCode::LeftAngledBracket	}, /* < > \ */
		
		/* Function keys*/
		{ 256	, KeyCode::Escape				},
		{ 257	, KeyCode::Enter				},
		{ 258	, KeyCode::Tab					},
		{ 259	, KeyCode::Backspace			},
		{ 260	, KeyCode::Insert				},
		{ 261	, KeyCode::Delete				},
		{ 262	, KeyCode::Right				},
		{ 263	, KeyCode::Left					},
		{ 264	, KeyCode::Down					},
		{ 265	, KeyCode::Up					},
		{ 266	, KeyCode::PageUp				},
		{ 267	, KeyCode::PageDown				},
		{ 268	, KeyCode::Home					},
		{ 269	, KeyCode::End					},
		{ 280	, KeyCode::CapsLock				},
		{ 281	, KeyCode::ScrollLock			},
		{ 282	, KeyCode::NumLock				},
		{ 283	, KeyCode::PrintScreen			},
		{ 284	, KeyCode::Pause				},
		{ 290	, KeyCode::F1					},
		{ 291	, KeyCode::F2					},
		{ 292	, KeyCode::F3					},
		{ 293	, KeyCode::F4					},
		{ 294	, KeyCode::F5					},
		{ 295	, KeyCode::F6					},
		{ 296	, KeyCode::F7					},
		{ 297	, KeyCode::F8					},
		{ 298	, KeyCode::F9					},
		{ 299	, KeyCode::F10					},
		{ 300	, KeyCode::F11					},
		{ 301	, KeyCode::F12					},
		{ 302	, KeyCode::F13					},
		{ 303	, KeyCode::F14					},
		{ 304	, KeyCode::F15					},
		{ 305	, KeyCode::F16					},
		{ 306	, KeyCode::F17					},
		{ 307	, KeyCode::F18					},
		{ 308	, KeyCode::F19					},
		{ 309	, KeyCode::F20					},
		{ 310	, KeyCode::F21					},
		{ 311	, KeyCode::F22					},
		{ 312	, KeyCode::F23					},
		{ 313	, KeyCode::F24					},
		{ 314	, KeyCode::F25					},

		/* Keypad */
		{ 320	, KeyCode::KP0					},
		{ 321	, KeyCode::KP1					},
		{ 322	, KeyCode::KP2					},
		{ 323	, KeyCode::KP3					},
		{ 324	, KeyCode::KP4					},
		{ 325	, KeyCode::KP5					},
		{ 326	, KeyCode::KP6					},
		{ 327	, KeyCode::KP7					},
		{ 328	, KeyCode::KP8					},
		{ 329	, KeyCode::KP9					},
		{ 330	, KeyCode::KPDecimal			},
		{ 331	, KeyCode::KPDivide				},
		{ 332	, KeyCode::KPMultiply			},
		{ 333	, KeyCode::KPSubtract			},
		{ 334	, KeyCode::KPAdd				},
		{ 335	, KeyCode::KPEnter				},
		{ 336	, KeyCode::KPEqual				},
		{ 340	, KeyCode::LeftShift			},
		{ 341	, KeyCode::LeftControl			},
		{ 342	, KeyCode::LeftAlt				},
		{ 343	, KeyCode::LeftSuper			},
		{ 344	, KeyCode::RightShift			},
		{ 345	, KeyCode::RightControl			},
		{ 346	, KeyCode::RightAlt				}, /* Belgian period <=> Alt gr */
		{ 347	, KeyCode::RightSuper			},
		{ 348	, KeyCode::Menu					},
	};
	
	std::vector<KeyCode> QWERTYKeyboard::m_RequireShift = {
		// Probably incomplete, don't have a QWERTY keyboard
		{ KeyCode::A				},
		{ KeyCode::B				},
		{ KeyCode::C				},
		{ KeyCode::D				},
		{ KeyCode::E				},
		{ KeyCode::F				},
		{ KeyCode::G				},
		{ KeyCode::H				},
		{ KeyCode::I				},
		{ KeyCode::J				},
		{ KeyCode::K				},
		{ KeyCode::L				},
		{ KeyCode::M				},
		{ KeyCode::N				},
		{ KeyCode::O				},
		{ KeyCode::P				},
		{ KeyCode::Q				},
		{ KeyCode::R				},
		{ KeyCode::S				},
		{ KeyCode::T				},
		{ KeyCode::U				},
		{ KeyCode::V				},
		{ KeyCode::W				},
		{ KeyCode::X				},
		{ KeyCode::Y				},
		{ KeyCode::Z				},
	};

	std::vector<KeyCode> QWERTYKeyboard::m_RequireRightAlt = {
		// Probably incomplete, don't have a QWERTY keyboard
	};

	std::vector<KeyCode> BelgianPeriodKeyboard::m_RequireShift = {

		{ KeyCode::SuperscriptThree		},
		{ KeyCode::D1					},
		{ KeyCode::D2					},
		{ KeyCode::D3					},
		{ KeyCode::D4					},
		{ KeyCode::D5					},
		{ KeyCode::D6					},
		{ KeyCode::D7					},
		{ KeyCode::D8					},
		{ KeyCode::D9					},
		{ KeyCode::D0					},
		{ KeyCode::DegreeSign			},
		{ KeyCode::Underscore			},

		{ KeyCode::A					},
		{ KeyCode::B					},
		{ KeyCode::C					},
		{ KeyCode::D					},
		{ KeyCode::E					},
		{ KeyCode::F					},
		{ KeyCode::G					},
		{ KeyCode::H					},
		{ KeyCode::I					},
		{ KeyCode::J					},
		{ KeyCode::K					},
		{ KeyCode::L					},
		{ KeyCode::M					},
		{ KeyCode::N					},
		{ KeyCode::O					},
		{ KeyCode::P					},
		{ KeyCode::Q					},
		{ KeyCode::R					},
		{ KeyCode::S					},
		{ KeyCode::T					},
		{ KeyCode::U					},
		{ KeyCode::V					},
		{ KeyCode::W					},
		{ KeyCode::X					},
		{ KeyCode::Y					},
		{ KeyCode::Z					},

		{ KeyCode::RightAngledBracket	},
		
		{ KeyCode::Umlaut				},
		{ KeyCode::Asterix				},
		{ KeyCode::Percent				},
		{ KeyCode::PoundSign			},

		{ KeyCode::QuestionMark			},
		{ KeyCode::Period				},
		{ KeyCode::Slash				},
		{ KeyCode::Plus					},
	};

	std::vector<KeyCode> BelgianPeriodKeyboard::m_RequireRightAlt = {

		{ KeyCode::VerticalBar			},
		{ KeyCode::AtSign				},
		{ KeyCode::Hash					},
		{ KeyCode::LeftCurlyBracket		},
		{ KeyCode::RightCurlyBracket	},

		{ KeyCode::LeftSquareBracket	},
		{ KeyCode::RightSquareBracket	},
		{ KeyCode::AcuteAccent			},
		{ KeyCode::GraveAccent			},

		{ KeyCode::Tilde				},
		{ KeyCode::EuroSign				},
		{ KeyCode::Backslash			},
	};
}
