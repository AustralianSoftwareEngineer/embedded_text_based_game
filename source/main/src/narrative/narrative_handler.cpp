#include <avr/pgmspace.h>
#include "narrative_handler.hpp"
// TODO Make dialogue option at the bottom say "- Continue" that a button press will normally progress to give more screen real estate for dialogue.


void NarrativeReadFromFlash(uint16_t selected_dialogue, NonPlayerableCharacterDialogue talking_NPC) 
{/*
  char buffer[80];
  strcpy_P(buffer, (char*)pgm_read_word(&(npcDialogueSpeakers[talking_NPC[selected_dialogue]])));
  Serial.println( buffer );
  delay( 500 );*/
}

//Old version, not updating to handle as prime example-> NarrativeShopkeeper. He's just that much more interesting.
void NarrativeStoryTeller(uint16_t selected_dialogue)
{
  char dialogue_data[75];
  strcpy_P(dialogue_data, (char*)pgm_read_word(&(storyteller_dialogue_tree[selected_dialogue])));
  Serial.println( dialogue_data );
  I2CDialoguePusher(dialogue_data, sizeof(dialogue_data));
  delay( 500 );
}

//Prime example
void NarrativeShopkeeper(uint16_t selected_dialogue)
{
  uint8_t dialogue_length = pgm_read_word_near(shopkeeper_dialogue_tree_length + selected_dialogue);

  char dialogue_data[dialogue_length];
  strcpy_P(dialogue_data, (char*)pgm_read_word(&(shopkeeper_dialogue_tree[selected_dialogue])));
  I2CDialoguePusher(dialogue_data, dialogue_length);
  Serial.println( dialogue_data );
  delay( 500 );
}
