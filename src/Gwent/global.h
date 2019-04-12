#ifndef GLOBAL_H
#define GLOBAL_H
#include <QApplication>
#include <QWidget>

//卡数
#define SUM 35
#define ROUND_ONE 11
#define ROUND_ONE_CHANGE 3
#define ROUND_TWO 3
#define ROUND_TWO_CHANGE 1
#define ROUND_THREE 3
#define ROUND_THREE_CHANGE 1

//color
#define WHITE argb(0, 255, 255, 255)

//timer
#define SECOND 1000
#define SECONDS 20
#define SHORT_TIME 200
#define ANI_TIME 300

//Name
#define FIRST_LIGHT 0
#define CLEAR_SKIES 1
#define RALLY 2
#define BITING_FROST 3
#define IMPENETRABLE_FOG 4
#define TORRENTIAL_RAIN 5
#define LACERATE 6
#define FULL_MOON_POTION 7
#define THUNDERBOLT_POTION 8
#define COMMANDER_S_HORN 9
#define BEKKER_S_TWISTED_MIRROR 10
#define GERALT_IGNI 11
#define DAGON 12
#define FOGLET 13
#define GE_ELS 14
#define CELAENO_HARPY 15
#define HARPY_EGG 16
#define HARPY_HATCHLING 17
#define WOODLAND_SPIRIT 18
#define RABID_WOLF 19
#define EARTH_ELEMENTAL 20
#define LESSER_EARTH_ELEMENTAL 21
#define CRONE_WEAVESS 22
#define CRONE_BREWESS 23
#define CRONE_WHISPESS 24
#define ARCHGRIFFIN 25
#define WILD_HUNT_RIDER 26
#define CARANTHIR 27
#define FRIGHTENER 28
#define UNSEEN_ELDER 29
#define ARACHAS 30
#define VRAN_WARRIOR 31
#define ARACHAS_BEHEMOTH 32
#define ARACHAS_HATCHLING 33
#define ROACH 34

//adress
const QString address_0 = ":/new/cards/iformation/First Light.json";
const QString address_1 = ":/new/cards/iformation/Clear Skies.json";
const QString address_2 = ":/new/cards/iformation/Rally.json";
const QString address_3 = ":/new/cards/iformation/Biting Frost.json";
const QString address_4 = ":/new/cards/iformation/Impenetrable Fog.json";
const QString address_5 = ":/new/cards/iformation/Torrential Rain.json";
const QString address_6 = ":/new/cards/iformation/Lacerate.json";
const QString address_7 = ":/new/cards/iformation/Full Moon Potion.json";
const QString address_8 = ":/new/cards/iformation/Thunderbolt Potion.json";
const QString address_9 = ":/new/cards/iformation/Commander's Horn.json";
const QString address_10 = ":/new/cards/iformation/Bekker's Twisted Mirror.json";
const QString address_11 = ":/new/cards/iformation/Geralt Igni.json";
const QString address_12 = ":/new/cards/iformation/Dagon.json";
const QString address_13 = ":/new/cards/iformation/Foglet.json";
const QString address_14 = ":/new/cards/iformation/Ge'els.json";
const QString address_15 = ":/new/cards/iformation/Celaeno Harpy.json";
const QString address_16 = ":/new/cards/iformation/harpy egg.json";
const QString address_17 = ":/new/cards/iformation/Harpy Hatchling.json";
const QString address_18 = ":/new/cards/iformation/Woodland Spirit.json";
const QString address_19 = ":/new/cards/iformation/Rabid Wolf.json";
const QString address_20 = ":/new/cards/iformation/Earth Elemental.json";
const QString address_21 = ":/new/cards/iformation/Lesser Earth Elemental.json";
const QString address_22 = ":/new/cards/iformation/Crone Weavess.json";
const QString address_23 = ":/new/cards/iformation/Crone Brewess.json";
const QString address_24 = ":/new/cards/iformation/Crone Whispess.json";
const QString address_25 = ":/new/cards/iformation/Archgriffin.json";
const QString address_26 = ":/new/cards/iformation/Wild Hunt Rider.json";
const QString address_27 = ":/new/cards/iformation/Caranthir.json";
const QString address_28 = ":/new/cards/iformation/Frightener.json";
const QString address_29 = ":/new/cards/iformation/Unseen Elder.json";
const QString address_30 = ":/new/cards/iformation/Arachas.json";
const QString address_31 = ":/new/cards/iformation/Vran Warrior.json";
const QString address_32 = ":/new/cards/iformation/Arachas Behemoth.json";
const QString address_33 = ":/new/cards/iformation/Arachas Hatchling.json";
const QString address_34 = ":/new/cards/iformation/Roach.json";

const QString address_battlefield = ":/new/cards/field/Battlefield.png";
const QString address_selectfield = ":/new/cards/field/Selectfield.png";
const QString address_menufield = ":/new/cards/field/menu.jpeg";
const QString address_scorefield = ":/new/cards/field/score.jpg";

const QString address_confirm = ":/new/cards/field/confirm.png";

const QString address_deck = ":/new/cards/Gwent/Deck.png";

const QString address_save = "save.json";
const QString address_save_2 = "save_2.json";

//size
#define WINDOW_WIDTH 1512
#define WINDOW_HEIGHT 945

#define CARD_S_WIDTH 500
#define CARD_S_HEIGHT 710

#define CARD_L_WIDTH 367
#define CARD_L_HEIGHT 420

#define CARD_DECK_WIDTH 165
#define CARD_DECK_HEIGHT 205

#define FIELD_WIDTH 3360
#define FIELD_HEIGHT 2100

#define ICON_WIDTH 157
#define ICON_HEIGHT 61

//menufield
#define MENUFIELD_BUTTON_LEFT 2800
#define MENUFIELD_1_TOP 500
#define MENUFIELD_S 200
#define MENUFIELD_V 120
#define MENUFIELD_V_2 150

//scorefield
#define SCORE_1_LEFT 1450
#define SCORE_2_LEFT 1800
#define SCORE_1_TOP 850
#define SCORE_2_TOP 1120
#define SCORE_3_TOP 1400
#define SCORE_BUTTON_LEFT 1600
#define SCORE_BUTTON_TOP 1900
#define SCORE_0_LEFT 1500
#define SCORE_0_TOP 300

//selectfield
#define SELECTFIELD_LEFT 765
#define SELECTFIELD_1_TOP 300
#define SELECTFIELD_2_TOP 535
#define SELECTFIELD_3_TOP 770
#define SELECTFIELD_4_TOP 1035
#define SELECTFIELD_5_TOP 1520
#define SELECTFIELD_STORE_WIDTH 1830
#define SELECTFIELD_STORE_HEIGHT 210
#define SELECTFIELD_INFO_LEFT 2710
#define SELECTFIELD_INFO_TOP 300
#define SELECTFIELD_INFO_WIDTH 650
#define SELECTFIELD_INFO_HEIGHT 1200
#define SELECTFIELD_LEADER_LEFT 320
#define SELECTFIELD_LEADER_TOP 1370
#define SELECTFIELD_NUMBER_LEFT 160
#define SELECTFIELD_NUMBER_TOP 280
#define SELECTFIELD_NUMBER_WIDTH 450
#define SELECTFIELD_NUMBER_2_LEFT 160
#define SELECTFIELD_NUMBER_2_TOP 380
#define SELECTFIELD_ICON_CONFIRM_LEFT 1580
#define SELECTFIELD_ICON_CONFIRM_TOP 1880

//battlefield
#define BATTLEFIELD_HAND_LEFT 1250
#define BATTLEFIELD_HAND_B_TOP 100
#define BATTLEFIELD_HAND_A_TOP 1743
#define BATTLEFIELD_HAND_WIDTH 1320
#define BATTLEFIELD_HAND_HEIGHT 252
#define BATTLEFIELD_LEADER_LEFT 880
#define BATTLEFIELD_WAR_LEFT 935
#define BATTLEFIELD_WAR_WIDTH 1485
#define BATTLEFIELD_WAR_B_3_TOP 420
#define BATTLEFIELD_WAR_B_2_TOP 621
#define BATTLEFIELD_WAR_B_1_TOP 825
#define BATTLEFIELD_WAR_A_1_TOP 1085
#define BATTLEFIELD_WAR_A_2_TOP 1290
#define BATTLEFIELD_WAR_A_3_TOP 1495
#define BATTLEFIELD_WAR_HEIGHT 189
#define BATTLEFIELD_POWER_LEFT 450
#define BATTLEFIELD_POWER_B_TOP 670
#define BATTLEFIELD_POWER_A_TOP 1330
#define BATTLEFIELD_POWER_DIS_LEFT 770
#define BATTLEFIELD_POWER_DIS_B_3_TOP 480
#define BATTLEFIELD_POWER_DIS_B_2_TOP 682
#define BATTLEFIELD_POWER_DIS_B_1_TOP 884
#define BATTLEFIELD_POWER_DIS_A_1_TOP 1142
#define BATTLEFIELD_POWER_DIS_A_2_TOP 1348
#define BATTLEFIELD_POWER_DIS_A_3_TOP 1548
#define BATTLEFIELD_PASS_LEFT 270
#define BATTLEFIELD_PASS_WIDTH 480
#define BATTLEFIELD_PASS_TOP 960
#define BATTLEFIELD_PASS_HEIGHT 480
#define BATTLEFIELD_DECK_LEFT 2995
#define BATTLEFIELD_DECK_B_TOP 120
#define BATTLEFIELD_DECK_A_TOP 1758
#define BATTLEFIELD_INFO_LEFT 2640
#define BATTLEFIELD_INFO_TOP 395
#define BATTLEFIELD_INFO_WIDTH 660
#define BATTLEFIELD_CHANGE_TOP 630
#define BATTLEFIELD_CHANGE_WIDTH 2570
#define BATTLEFIELD_TEXT_CHANGE_LEFT 1280
#define BATTLEFIELD_TEXT_CHANGE_TOP 300
#define BATTLEFIELD_BUTTON_LEFT 1280
#define BATTLEFIELD_BUTTON_TOP 1700

//font
#define FONT_S 50
#define FONT_M 60
#define FONT_L 130

//scale
#define SCALE_FILED_WINDOW QApplication::desktop()->width()/3360
#define SCALE_SELECTFIELD_CARD_L 0.5
#define SCALE_SELECTFIELD_CARD_L_INFO 1.8
#define SCALE_SELECTFIELD_CARD_L_LEADER 0.9
#define SCALE_SELECTFIELD_ICON 1.2
#define SCALE_BATTLEFIELD_CARD_L_ON 0.45
#define SCALE_BATTLEFIELD_CARD_L_IN 0.6
#define SCALE_BATTLEFIELD_CARD_L_INFO 1.8
#define SCALE_BATTLEFIELD_CARD_DECK 0.68
#define SCALE_BATTLEFIELD_CARD_CHANGE 2
#define SCALE_MENUFIELD_BUTTON 1.5

#endif // GLOBAL_H
