#include "USB.h"
#include "USBHIDMouse.h"
#include "USBHIDKeyboard.h"


USBHIDMouse Mouse;
USBHIDKeyboard Keyboard;


const int switchPin = 2;
const int buttonPin = 3;

//bool oldActive = false;
//bool active = false;
bool lastButtonState = LOW;

// 

struct CheatEntry {
  const char* text;
  int count;
};

CheatEntry cheats[] = {
  {"ad5bcf05-c082-4ead-be9c-2f16c6d3dde7", 100}, //Marksman’s bolt
  {"1abe5629-ffc4-4693-9cd7-700ea75e3386", 100}, // Black arrow
  {"88c08905-fb68-46e2-813e-4176d12cc493", 0}, // Ambrose’s broken sword
  {"3db25e6e-dfe2-4b06-a079-80e6064073c4", 100}, // Antlers
  {"c76db6a9-9f8c-487a-bb0b-48b16b47b75f", 100}, // Bezoar
  {"c5b24e5e-69f0-4ed9-bc74-96c3de9dc677", 100}, // Black feather
  {"a4f0f4c8-dc3f-4cb2-be89-f0f56fbb09fa", 100}, // Boar’s tusk
  {"9a042027-bf77-450b-8a73-530b130362bd", 0}, // Broken axe
  {"c8831b16-f218-4d77-93ab-8f2402508677", 0}, // Broken guild longsword
  {"a40e513f-045e-421c-99c9-c10dae3d9fe1", 100}, // Cave Mushroom
  {"f879ac63-2ce2-4114-83a2-89643c1ed102", 100}, // Charcoal
  {"ec24c6c7-f5bd-4d27-aeef-9a5676686ff8", 100}, // Charcoal water
  {"2d5e420c-3678-4cc1-a7d1-6d585dbf2d1b", 100}, // Cheater's noose
  {"33392df2-2b85-4875-998b-c313de495f57", 100}, // Cobweb
  {"1fe0e850-e07d-45f0-ade0-26f030a63da4", 100}, // Coin sword pommel
  {"05f2b2cc-fd48-496e-ab0c-45160910dfde", 100}, // Commemorative coin
  {"8b7515e1-21fb-4c18-b3da-86fabb5025bd", 100}, // Copper
  {"e5ac7c40-263d-4fba-8c00-343e9b112aef", 100}, // Cow skin
  {"af9bcfd0-6cb5-4944-bd8f-a53d2253f51e", 100}, // Decorated sword pommel
  {"a1dda25f-3a35-4376-b198-4e5173c742a8", 100}, // Deer skin
  {"4f7a7d02-b8cb-4bcc-9b3e-edc1992ee580", 100}, // Eight-sided sword pommel
  {"87a568f2-79f7-415f-a690-9a04c4585455", 100}, // Exotic wood
  {"4a6269c1-5c01-473d-ad69-e0a0c41643e7", 100}, // Fastening material
  {"abb6cc5a-3592-406f-82ab-edfb73e219be", 100}, // Fly agaric
  {"3f5426ab-1364-46f9-9b3c-c84e1654a441", 100}, // Found horseshoe
  {"3c1c0ae2-731e-40c1-a917-024fb3f000da", 100}, // Frankfurt’s steel
  {"347e61a6-d36e-4d1e-99ce-98c8ecbeee73", 100}, // Frankincense
  {"38ea59b9-ead9-4fb5-a62a-2051abd844a2", 100}, // Gall
  {"ddbdf313-f3be-47b5-9f6e-20c1124c69d2", 100}, // Holy nail
  {"83ddc936-0659-44d0-a16e-0a3e187c5027", 100}, // Horn
  {"6bfe50b1-dafb-4bf7-a1d9-1f61feb3ac53", 100}, // Horned sword guard
  {"92aa6120-028e-48ee-8ed1-1c5f91afaa26", 100}, // Iron
  {"b979154f-5b69-45dd-848d-b56a1d3e6e0e", 100}, // Lard
  {"55be7c8b-7ef1-4e45-820d-d04a2497f016", 100}, // Leached coal
  {"d01f5606-5bba-42c1-9a48-b065e7a92ad7", 100}, // Ordinary sword guard
  {"9023c10e-025c-4580-9b08-b0919e9f7346", 100}, // Pear sword pommel
  {"493563fc-0d46-4ee7-a947-85d6c4063003", 100}, // Pig skin
  {"2bf46965-a851-4602-8282-cbefe7f24945", 100}, // Raven feathers
  {"ce3b63c5-b749-423a-b189-d98d0e14f781", 100}, // Red feathers
  {"1c933935-d4b3-4884-8228-a4cde0c3a96d", 100}, // Reinforced sword guard
  {"d2a23942-45c1-4d5a-bcbc-96a09611af75", 100}, // Rooster tail feather
  {"8cf956d4-39d6-4e9d-9010-95f8f2772ad9", 100}, // Saltpetre
  {"94d8f5f1-20a7-4840-98ad-1d198d381389", 100}, // Scrap metal
  {"54f297f8-62c0-41b5-9ab4-892c7475fc6a", 100}, // Steel
  {"bc09cb07-fb9d-45be-8f55-d42b999c6341", 100}, // Straight sword guard
  {"0513eeae-05a8-4ca7-8719-443cb0d906d5", 100}, // Suplhur
  {"4a4da84c-f12a-4bc8-94dc-a7d8d76788ea", 100}, // Toledo’s steel
  {"20774cbd-f9f8-48c8-99ab-632985b7ea56", 100}, // White feathers
  {"651333f0-36d1-4321-975f-bc7833a773eb", 100}, // Winning horseshoe
  {"7b1c57a3-54fd-441f-8cad-21157bd1a85b", 100} // Wolf fangs
};
// CheatEntry cheats[] = {
//   {"ad5bcf05-c082-4ead-be9c-2f16c6d3dde7", 2}, //Marksman’s bolt
//   {"1abe5629-ffc4-4693-9cd7-700ea75e3386", 2}, // Black arrow
//   {"88c08905-fb68-46e2-813e-4176d12cc493", 0}, // Ambrose’s broken sword
//   {"3db25e6e-dfe2-4b06-a079-80e6064073c4", 2}, // Antlers
//   {"c76db6a9-9f8c-487a-bb0b-48b16b47b75f", 2}, // Bezoar
//   {"c5b24e5e-69f0-4ed9-bc74-96c3de9dc677", 2}, // Black feather
//   {"a4f0f4c8-dc3f-4cb2-be89-f0f56fbb09fa", 2}, // Boar’s tusk
//   {"9a042027-bf77-450b-8a73-530b130362bd", 0}, // Broken axe
//   {"c8831b16-f218-4d77-93ab-8f2402508677", 0}, // Broken guild longsword
//   {"a40e513f-045e-421c-99c9-c10dae3d9fe1", 2}, // Cave Mushroom
//   {"f879ac63-2ce2-4114-83a2-89643c1ed102", 2}, // Charcoal
//   {"ec24c6c7-f5bd-4d27-aeef-9a5676686ff8", 2}, // Charcoal water
//   {"2d5e420c-3678-4cc1-a7d1-6d585dbf2d1b", 2}, // Cheater's noose
//   {"33392df2-2b85-4875-998b-c313de495f57", 2}, // Cobweb
//   {"1fe0e850-e07d-45f0-ade0-26f030a63da4", 2}, // Coin sword pommel
//   {"05f2b2cc-fd48-496e-ab0c-45160910dfde", 2}, // Commemorative coin
//   {"8b7515e1-21fb-4c18-b3da-86fabb5025bd", 2}, // Copper
//   {"e5ac7c40-263d-4fba-8c00-343e9b112aef", 2}, // Cow skin
//   {"af9bcfd0-6cb5-4944-bd8f-a53d2253f51e", 2}, // Decorated sword pommel
//   {"a1dda25f-3a35-4376-b198-4e5173c742a8", 2}, // Deer skin
//   {"4f7a7d02-b8cb-4bcc-9b3e-edc1992ee580", 2}, // Eight-sided sword pommel
//   {"87a568f2-79f7-415f-a690-9a04c4585455", 2}, // Exotic wood
//   {"4a6269c1-5c01-473d-ad69-e0a0c41643e7", 2}, // Fastening material
//   {"abb6cc5a-3592-406f-82ab-edfb73e219be", 2}, // Fly agaric
//   {"3f5426ab-1364-46f9-9b3c-c84e1654a441", 2}, // Found horseshoe
//   {"3c1c0ae2-731e-40c1-a917-024fb3f000da", 2}, // Frankfurt’s steel
//   {"347e61a6-d36e-4d1e-99ce-98c8ecbeee73", 2}, // Frankincense
//   {"38ea59b9-ead9-4fb5-a62a-2051abd844a2", 2}, // Gall
//   {"ddbdf313-f3be-47b5-9f6e-20c1124c69d2", 2}, // Holy nail
//   {"83ddc936-0659-44d0-a16e-0a3e187c5027", 2}, // Horn
//   {"6bfe50b1-dafb-4bf7-a1d9-1f61feb3ac53", 2}, // Horned sword guard
//   {"92aa6120-028e-48ee-8ed1-1c5f91afaa26", 2}, // Iron
//   {"b979154f-5b69-45dd-848d-b56a1d3e6e0e", 2}, // Lard
//   {"55be7c8b-7ef1-4e45-820d-d04a2497f016", 2}, // Leached coal
//   {"d01f5606-5bba-42c1-9a48-b065e7a92ad7", 2}, // Ordinary sword guard
//   {"9023c10e-025c-4580-9b08-b0919e9f7346", 2}, // Pear sword pommel
//   {"493563fc-0d46-4ee7-a947-85d6c4063003", 2}, // Pig skin
//   {"2bf46965-a851-4602-8282-cbefe7f24945", 2}, // Raven feathers
//   {"ce3b63c5-b749-423a-b189-d98d0e14f781", 2}, // Red feathers
//   {"1c933935-d4b3-4884-8228-a4cde0c3a96d", 2}, // Reinforced sword guard
//   {"d2a23942-45c1-4d5a-bcbc-96a09611af75", 2}, // Rooster tail feather
//   {"8cf956d4-39d6-4e9d-9010-95f8f2772ad9", 2}, // Saltpetre
//   {"94d8f5f1-20a7-4840-98ad-1d198d381389", 2}, // Scrap metal
//   {"54f297f8-62c0-41b5-9ab4-892c7475fc6a", 2}, // Steel
//   {"bc09cb07-fb9d-45be-8f55-d42b999c6341", 2}, // Straight sword guard
//   {"0513eeae-05a8-4ca7-8719-443cb0d906d5", 2}, // Suplhur
//   {"4a4da84c-f12a-4bc8-94dc-a7d8d76788ea", 2}, // Toledo’s steel
//   {"20774cbd-f9f8-48c8-99ab-632985b7ea56", 2}, // White feathers
//   {"651333f0-36d1-4321-975f-bc7833a773eb", 2}, // Winning horseshoe
//   {"7b1c57a3-54fd-441f-8cad-21157bd1a85b", 2} // Wolf fangs
// };
const int cheatCount = sizeof(cheats) / sizeof(cheats[0]);


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(switchPin, INPUT_PULLUP);
  USB.begin();
  Mouse.begin();
  Serial.begin(9600);
}

void forge() {
  Mouse.press(MOUSE_LEFT);
  delay(1000);
  Mouse.release(MOUSE_LEFT);
}


void cheat() {
  String prefix = "wh_cheat_addItem ";
  prefix.replace("_", "?");

  for (int i = 0; i < cheatCount; i++) {
    for (int j = 0; j < cheats[i].count; j++) {
      String itemId = cheats[i].text;
      itemId.replace("-", "/");
      String fullText = prefix + itemId;
      Keyboard.println(fullText);

      delay(1500);
    }
  }
}

void loop() {
  bool switchState = digitalRead(switchPin);
  //Serial.println(switchState);
  if (switchState == HIGH) {
    //Serial.println("Forge");
    forge();
  }

  bool buttonState = digitalRead(buttonPin);
  //Serial.println(buttonState);
  if (buttonState == HIGH && lastButtonState == LOW) {
    //Serial.println("Cheat");
    cheat();
  }
  lastButtonState = buttonState;


  delay(100);
}
