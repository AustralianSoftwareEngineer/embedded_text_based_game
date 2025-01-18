
// Might end up using Python to handle the sizing dynamically before compile.


// Intro
const char shopkeeper_intro_one[] PROGMEM = {"Another one? *Grunts* We don't keep tabs here."};

// Repetitve
const char shopkeeper_banter_one[] PROGMEM = {"Welcome back. Surprised to see that you of all people are still alive."};
const char shopkeeper_banter_two[] PROGMEM = {"Your here again? You might start to become a regular."};
const char shopkeeper_banter_three[] PROGMEM = {"Haven't seen them last as long as you have."};
const char shopkeeper_banter_four[] PROGMEM = {"Really making yourself at home here, huh?"};
const char shopkeeper_banter_five[] PROGMEM = {"Are you trying to give me a chance to miss you?"};
const char shopkeeper_banter_six[] PROGMEM = {"Same price as always, living isn't a discount."};
const char shopkeeper_banter_seven[] PROGMEM = {"You used to look a bit more lively."};
const char shopkeeper_banter_eight[] PROGMEM = {"Sorry tae say but a potion wont fix that."};
const char shopkeeper_banter_nine[] PROGMEM = {"Still the same flavour, I don't make 'em."};
const char shopkeeper_banter_ten[] PROGMEM = {"I just cleaned tae floor."};

const uint8_t shopkeeper_banter_one_length PROGMEM = sizeof(shopkeeper_banter_one) / sizeof(shopkeeper_banter_one[0]);
const uint8_t shopkeeper_banter_two_length PROGMEM = sizeof(shopkeeper_banter_two) / sizeof(shopkeeper_banter_two[0]);
const uint8_t shopkeeper_banter_three_length PROGMEM = sizeof(shopkeeper_banter_three) / sizeof(shopkeeper_banter_three[0]);
const uint8_t shopkeeper_banter_four_length PROGMEM = sizeof(shopkeeper_banter_four) / sizeof(shopkeeper_banter_four[0]);
const uint8_t shopkeeper_banter_five_length PROGMEM = sizeof(shopkeeper_banter_five) / sizeof(shopkeeper_banter_five[0]);
const uint8_t shopkeeper_banter_six_length PROGMEM = sizeof(shopkeeper_banter_six) / sizeof(shopkeeper_banter_six[0]);
const uint8_t shopkeeper_banter_seven_length PROGMEM = sizeof(shopkeeper_banter_seven) / sizeof(shopkeeper_banter_seven[0]);
const uint8_t shopkeeper_banter_eight_length PROGMEM = sizeof(shopkeeper_banter_eight) / sizeof(shopkeeper_banter_eight[0]);
const uint8_t shopkeeper_banter_nine_length PROGMEM = sizeof(shopkeeper_banter_nine) / sizeof(shopkeeper_banter_nine[0]);
const uint8_t shopkeeper_banter_ten_length PROGMEM = sizeof(shopkeeper_banter_ten) / sizeof(shopkeeper_banter_ten[0]);


// Initialising the list
const char *const shopkeeper_dialogue_tree[] PROGMEM = {
  shopkeeper_banter_one,
  shopkeeper_banter_two,
  shopkeeper_banter_three,
  shopkeeper_banter_four,
  shopkeeper_banter_five,
  shopkeeper_banter_six,
  shopkeeper_banter_seven,
  shopkeeper_banter_eight,
  shopkeeper_banter_nine,
  shopkeeper_banter_ten,
  shopkeeper_intro_one
};

const uint8_t *const shopkeeper_dialogue_tree_length[] PROGMEM = {
  shopkeeper_banter_one_length,
  shopkeeper_banter_two_length,
  shopkeeper_banter_three_length,
  shopkeeper_banter_four_length,
  shopkeeper_banter_five_length,
  shopkeeper_banter_six_length,
  shopkeeper_banter_seven_length,
  shopkeeper_banter_eight_length,
  shopkeeper_banter_nine_length,
  shopkeeper_banter_ten
};