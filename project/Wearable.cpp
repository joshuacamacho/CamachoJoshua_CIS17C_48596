#include "Wearable.h"


Wearable::Wearable(int itemlevel)
{
  ilevel = itemlevel;
  /*A roll to pick the armor slot  */
  int rollslot = rand() % 7;
  /*A roll to choose between magic(1) or 
    attack damage item(0)             */
  int rolltype = rand() % 2;
  if (rolltype == 0){
    type = FIGHTER;
    defense = (rand()%itemlevel) + itemlevel;
    attack = (rand() % itemlevel) + (itemlevel/2);
    magic = 0;
  }
  else{
    type = MAGE;
    defense = (rand() % itemlevel) + (itemlevel/2);
    attack = 0;
    magic = (rand() % itemlevel) + itemlevel;
  }
  switch (rollslot){
  case 0:
    slot = HEAD;
    break;
  case 1:
    slot = CHEST;
    break;
  case 2:
    slot = LEGS;
    break;
  case 3:
    slot = FEET;
    break;
  case 4:
    slot = ARMS;
    break;
  case 5:
    slot = GLOVES;
    break;
  case 6:
    slot = WEAPON;
    
    break;
  }
  if (slot == WEAPON) generateWeapon();
  else generateArmor();
}


Wearable::~Wearable()
{
}

int Wearable::getDefense(){
  return this->defense;
}
int Wearable::getMagic(){
  return this->magic;
}

int Wearable::getAttack(){
  return this->attack;
}

std::string Wearable::getSlot(){
  std::string s;
  if (slot == HEAD) s = "Head";
  else if (slot == CHEST) s = "Chest";
  else if (slot == LEGS) s = "Legs";
  else if (slot == FEET) s = "Feet";
  else if (slot == ARMS) s = "Arms";
  else if (slot == GLOVES) s = "Gloves";
  else if (slot == WEAPON) s = "Weapon";
  return s;
}

void Wearable::generateArmor(){
  std::string s;
  int defmod = 0;
  int atkmod = 0;
  int magmod = 0;
  int roll = rand() % 6;
  //generate prefix and set initial modifiers
  switch (roll){
  case 0:
    if (type == MAGE){
      s += "Ripped ";
      defmod -= 5;
    }
    else{
      s += "Rusty ";
      defmod -= 5;
    }
    break;

  case 1:
    if (type == MAGE){
      s += "Torn ";
      defmod -= 2;
    }
    else{
      s += "Dull ";
      defmod -= 2;
    }
    break;

  case 2:
    if (type == MAGE){
      s += "Normal ";
    }
    else{
      s += "Normal ";
    }
    break;

  case 3:
    if (type == MAGE){
      s += "Magic ";
      magmod += 5;
    }
    else{
      s += "Powerful ";
      atkmod += 5;
    }
    break;

  case 4:
    if (type == MAGE){
      s += "Legendary ";
      magmod += 5;
      defmod += 5;
    }
    else{
      s += "Legendary ";
      atkmod += 5;
      defmod += 5;
    }
    break;

  case 5:
    if (type == MAGE){
      s += "Ancient ";
      magmod += 7;
      defmod += 5;
    }
    else{
      s += "Heroic ";
      atkmod += 7;
      defmod += 5;
    }
    break;
  }//end switch

  //add baseName to prefix
  s += baseName();

  switch (slot){
  case HEAD:
    if (type == MAGE){
      s += " Hood ";
    }
    else{
      s += " Helmet ";
    }
    break;
  case CHEST:
    if (type == MAGE){
      s += " Robe ";
    }
    else{
      s += " Chestplate ";
    }
    break;
  case LEGS:
    if (type == MAGE){
      s += " Pants ";
    }
    else{
      s += " Legplates ";
    }
    break;
  case FEET:
    if (type == MAGE){
      s += " Sandals ";
    }
    else{
      s += " Boots ";
    }
    break;
  case ARMS:
    if (type == MAGE){
      s += " Sleeves ";
    }
    else{
      s += " Armplates ";
    }
    break;
  case GLOVES:
    if (type == MAGE){
      s += " Gloves ";
    }
    else{
      s += " Plate Gloves ";
    }
    break;
  }

  //add suffix
  roll = rand() % 50;
  if (roll <= 25){
    if (type == MAGE){
      s += "of the Apprentice Mage";
      magmod += 1;
    }
    else{
      s += "of the Squire";
      atkmod += 1;
    }
  }
  else if (roll > 25 && roll <= 35){
    s += "of Defense";
    defmod += 5;
  }
  else if (roll > 35 && roll <= 45){
    if (type == MAGE){
      s += "of Magic";
      magmod += 5;
    }
    else{
      s += "of Attack";
      atkmod += 5;
    }
  }
  else if (roll > 45){
    if (type == MAGE){
      s += "of the Battle Mage";
      magmod += 5;
    }
    else{
      s += "of the Valiant Warrior";
      atkmod += 5;
    }
    defmod += 5;
  }
  name = s;
  attack += atkmod;
  magic += magmod;
  defense += defmod;
}

void Wearable::generateWeapon(){
  std::string s;
  int roll = rand() % 20;
  int mod=0;
  switch (roll){
  case 0:s += "Smelly";
    mod += 1;
    break;
  case 1:s += "Strong";
    mod += 10;
    break;
  case 2:s += "Bent";
    mod += 2;
    break;
  case 3:s += "Glowing";
    mod += 9;
    break;
  case 4:s += "Firery";
    mod += 11;
    break;
  case 5:s += "Bloody";
    mod += 7;
    break;
  case 6:s += "Rusty";
    mod += 2;
    break;
  case 7:s += "Quick";
    mod += 6;
    break;
  case 8:s += "Heavy";
    mod += 12;
    break;
  case 9:s += "Sharp";
    mod += 7;
    break;
  case 10:s += "Dull";
    mod += 4;
    break;
  case 11:s += "Magical";
    mod += 9;
    break;
  case 12:s += "Broken";
    mod += 1;
    break;
  case 13:s += "Hellforged";
    mod += 6;
    break;
  case 14:s += "Angelforged";
    mod += 6;
    break;
  case 15:s += "Demon";
    mod += 5;
    break;
  case 16:s += "Icey";
    mod += 5;
    break;
  case 17:s += "Descriptionless";
    mod += 8;
    break;
  case 18:s += "Amazing";
    mod += 8;
    break;
  case 19:s += "Long Lost";
    mod += 6;
    break;
  }
  if (type == MAGE){
    roll = rand() % 5;
    switch (roll){
    case 0:
      s += " Staff ";
      mod += 5;
      break;
    case 1:
      s += " Scepter ";
      mod += 3;
      break;
    case 2:
      s += " Rod ";
      mod += 2;
      break;
    case 3:
      s += " Orb ";
      mod += 5;
      break;
    case 4:
      s += " Tomb ";
      mod += 8;
      break;
    }
  }
  else{
    roll = rand() % 20;
    switch (roll){
    case 0:s += " Mace ";
     mod += 5;
      break;
    case 1:s += " Halberd ";
     mod += 6;
      break;
    case 2:s += " Sword ";
     mod += 5;
      break;
    case 3:s += " Dagger ";
     mod += 3;
      break;
    case 4:s += " Lance ";
     mod += 7;
      break;
    case 5:s += " Club ";
     mod += 6;
      break;
    case 6:s += " Morning Glory ";
     mod += 5;
      break;
    case 7:s += " Iron Fists ";
     mod += 2;
      break;
    case 8:s += " Dragon Tooth ";
     mod += 10;
      break;
    case 9:s += " Greatsword ";
     mod += 9;
      break;
    case 10:s += " Throwing Dagger ";
     mod += 2;
      break;
    case 11:s += " Axe ";
     mod += 4;
      break;
    case 12:s += " Greataxe ";
     mod += 8;
      break;
    case 13:s += " Staff ";
     mod += 4;
      break;
    case 14:s += " Bow ";
     mod += 4;
      break;
    case 15:s += " Rapier ";
     mod += 5;
      break;
    case 16:s += " Shiv ";
     mod += 3;
      break;
    case 17:s += " Moonblade ";
     mod += 6;
      break;
    case 18:s += " Pike ";
     mod += 7;
      break;
    case 19:s += " Broadsword ";
     mod += 7;
      break;
    }
  }
  
  roll = rand() % 20;
  switch (roll){
  case 0:s += "of the Arctic North";
    mod += 4;
    break;
  case 1:s += "of the Southern Tribes";
    mod += 3;
    break;
  case 2:s += "of the Dragonborn";
    mod += 5;
    break;
  case 3:s += "of Curious Origins";
    mod += 10;
    break;
  case 4:s += "of the Nightwatch";
    mod += 6;
    break;
  case 5:s += "of the Moonwatch";
    mod += 3;
    break;
  case 6:s += "of the Dark Brotherhood";
    mod += 2;
    break;
  case 7:s += "of the Secret Assassins";
    mod += 4;
    break;
  case 8:s += "of Power";
    mod += 10;
    break;
  case 9:s += "of Swiftness";
    mod += 6;
    break;
  case 10:s += "of Filth";
    mod += 1;
    break;
  case 11:s += "of Nobility";
    mod += 5;
    break;
  case 12:s += "of the Gentleman";
    mod += 7;
    break;
  case 13:s += "of the Monks";
    mod += 5;
    break;
  case 14:s += "of the Righteous Clerics";
    mod += 4;
    break;
  case 15:s += "of Magic";
    mod += 4;
    break;
  case 16:s += "of The Great Human Nation";
    mod += 4;
    break;
  case 17:s += "of the Stonebrought Dwarves";
    mod += 5;
    break;
  case 18:s += "of Mysterious Origins";
    mod += 3;
    break;
  case 19:s += "of the Night Elves";
    mod += 4;
    break;
  }
  name = s;
  defense = 0;
  if (type == MAGE){
    magic = 0;
    magic += (mod * 4);
  }
  else{
    attack = 0;
    attack += (mod * 4);
  }
}

std::string Wearable::baseName(){
  std::string s;
  if (ilevel <= 10){
    if (type == MAGE){
      s = "Ragged";
    }
    else{
      s = "Bronze";
    }
  }
  else if (ilevel > 10 && ilevel<= 20){
    if (type == MAGE){
      s = "Reinforced CLoth";
    }
    else{
      s = "Iron";
    }
  }
  else if (ilevel > 20 && ilevel <= 30){
    if (type == MAGE){
      s = "Enchanted Cloth";
    }
    else{
      s = "Mithril";
    }
  }
  else if (ilevel > 30){
    if (type == MAGE){
      s = "Dragon Skin";
    }
    else{
      s = "Dragon Scale";
    }
  }
  return s;
}
std::string Wearable::getName(){
  return name;
}