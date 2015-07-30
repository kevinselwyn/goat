#ifndef GOAT_H
#define GOAT_H

#define SKILL_NOTHING       0x0000
#define SKILL_BARTER        0x0001
#define SKILL_BIGGUNS       0x0002
#define SKILL_ENERGYWEAPONS 0x0004
#define SKILL_EXPLOSIVES    0x0008
#define SKILL_LOCKPICK      0x0010
#define SKILL_MEDICINE      0x0020
#define SKILL_MELEE         0x0040
#define SKILL_REPAIR        0x0080
#define SKILL_SCIENCE       0x0100
#define SKILL_SMALLGUNS     0x0200
#define SKILL_SNEAK         0x0400
#define SKILL_SPEECH        0x0800
#define SKILL_UNARMED       0x1000

#define COUNT_QUESTIONS     10
#define COUNT_CHOICES       4
#define COUNT_ANSWERS       13
#define COUNT_OCCUPATIONS   13

typedef struct choice {
	char *text;
	int skill;
} choice;

typedef struct question {
	char *text;
	choice choices[COUNT_CHOICES];
} question;

question questions[COUNT_QUESTIONS] = {
	{
		"You are approached by a frenzied Vault scientist, who yells, \"I'm going to put my quantum harmonizer in your photonic resonation chamber!\" What's your response?",
		{
			{
				"\"But doctor, wouldn't that cause a parabolic destabilization of the fission singularity?\"",
				SKILL_SCIENCE
			},
			{
				"\"Yeah? Up yours too, buddy!\"",
				SKILL_SPEECH
			},
			{
				"Say nothing, grab a nearby pipe and hit the scientist in the head to knock him out. For all you knew, he was planning to blow up the vault.",
				SKILL_MELEE
			},
			{
				"Say nothing, but slip away before the scientist can continue his rant.",
				SKILL_SNEAK
			}
		}
	},
	{
		"While working as an intern in the Clinic, a patient with a strange infection on his foot stumbles through the door. The infection is spreading at an alarming rate, but the doctor has stepped out for a while. What do you do?",
		{
			{
				"Amputate the foot before the infection spreads",
				SKILL_MELEE
			},
			{
				"Scream for help",
				SKILL_SPEECH
			},
			{
				"Medicate the infected area to the best of your abilities",
				SKILL_MEDICINE
			},
			{
				"Restrain the patient, and merely observe as the infection spreads",
				SKILL_SCIENCE
			}
		}
	},	
	{
		"You discover a young boy lost in the lower levels of the Vault. He's hungry and frightened, but also appears to be in possession of stolen property. What do you do?",
		{
			{
				"Give the boy a hug and tell him everything will be okay",
				SKILL_SPEECH
			},
			{
				"Confiscate the property by force, and leave him there as punishment",
				SKILL_UNARMED
			},
			{
				"Pick the boy's pocket to take the stolen property for yourself, and leave the boy to his fate",
				SKILL_SNEAK
			},
			{
				"Lead the boy to safety, then turn him over to the overseer",
				SKILL_NOTHING
			}
		}
	},
	{
		"Congratulations! You made one of the Vault 101 baseball teams! Which position do you prefer?",
		{
			{
				"Pitcher",
				SKILL_EXPLOSIVES
			},
			{
				"Catcher",
				SKILL_BIGGUNS
			},
			{
				"Designated Hitter",
				SKILL_MELEE
			},
			{
				"None, you wish the vault had a soccer team",
				SKILL_UNARMED
			}
		}
	},
	{
		"Your grandmother invites you to tea, but you're surprised when she gives you a pistol and orders you to kill another Vault resident. What do you do?",
		{
			{
				"Obey your elder and kill the Vault resident with the pistol.",
				SKILL_SMALLGUNS
			},
			{
				"Offer your most prized possession for the resident's life.",
				SKILL_BARTER
			},
			{
				"Ask granny for a minigun instead. After all, you don't want to miss.",
				SKILL_BIGGUNS
			},
			{
				"Throw your tea in granny's face.",
				SKILL_EXPLOSIVES
			}
		}
	},
	{
		"Old Mr. Abernathy has locked himself in his quarters again, and you've been ordered to get him out. How do you proceed?",
		{
			{
				"Use a bobby pin to pick the lock on the door.",
				SKILL_LOCKPICK
			},
			{
				"Trade a Vault hoodlum for his cherry bomb and blow open the lock.",
				SKILL_EXPLOSIVES | SKILL_BARTER
			},
			{
				"Go to the armory, retrieve a laser pistol, and blow the lock off.",
				SKILL_ENERGYWEAPONS
			},
			{
				"Walk away, and let the old coot rot.",
				SKILL_REPAIR
			}
		}
	},
	{
		"Oh, no! You've been exposed to radiation, and a mutated hand has grown out of your stomach! What's the best course of treatment?",
		{
			{
				"A bullet to the brain",
				SKILL_SMALLGUNS
			},
			{
				"Large doses of anti-mutagen agent",
				SKILL_MEDICINE
			},
			{
				"Prayer. Maybe God will spare you in exchange for a life of pious devotion.",
				SKILL_BARTER
			},
			{
				"Removal of the mutated tissue with a precision laser",
				SKILL_ENERGYWEAPONS
			}
		}
	},
	{
		"A fellow Vault 101 resident is in possession of a Grognak the Barbarian comic book, issue number 1. You want it. What's the best way to obtain it?",
		{
			{
				"Trade the comic book for one of your own valuable possessions",
				SKILL_BARTER
			},
			{
				"Steal the comic book at gunpoint",
				SKILL_SMALLGUNS
			},
			{
				"Sneak into the resident's quarters, and steal the comic book from his desk",
				SKILL_SNEAK
			},
			{
				"Slip some knock out drops into the resident's Nuka-Cola, and take the comic book when he's unconscious.",
				SKILL_MEDICINE
			}
		}
	},
	{
		"You decide it would be fun to play a prank on your father. You enter his private restroom when no one is looking, and....",
		{
			{
				"Loosen some bolts on some pipes. When the sink is turned on, the room will flood.",
				SKILL_REPAIR
			},
			{
				"Put a firecracker in the toilet. That's sure to cause some chaos",
				SKILL_EXPLOSIVES
			},
			{
				"Break into the locked medicine cabinet and replace his high blood pressure medication with sugar pills",
				SKILL_MEDICINE
			},
			{
				"Manipulate the power wattage on his razor, so he'll get an electric shock next time he shaves",
				SKILL_LOCKPICK
			}
		}
	},
	{
		"Who is indisputably the most important person in Vault 101: He who shelters us from the harshness of the atomic wasteland, and to whom we owe everything we have, including our lives?",
		{
			{
				"The Overseer",
				SKILL_NOTHING
			},
			{
				"The Overseer",
				SKILL_NOTHING
			},
			{
				"The Overseer",
				SKILL_NOTHING
			},
			{
				"The Overseer",
				SKILL_NOTHING
			}
		}
	}
};

typedef struct occupation {
	char *title, *description;
	int skill, count;
} occupation;

occupation occupations[COUNT_OCCUPATIONS] = {
	{
		"Vault chaplain",
		"\"They say the G.O.A.T never lies. According to this, you're slated to be the next vault ... Chaplain. God help us all.\"",
		SKILL_BARTER,
		0
	},
	{
		"Laundry cannon operator",
		"\"Well according to this, you're in line to be trained as a laundry cannon operator. First time for everything indeed.\"",
		SKILL_BIGGUNS,
		0
	},
	{
		"Pedicurist",
		"\"It's nice to know I can still be surprised. Pedicurist! I might have guessed Manicurist, or even Masseuse. But apparently you're a foot person.\"",
		SKILL_ENERGYWEAPONS,
		0
	},
	{
		"Waste management specialist",
		"\"It says here you're perfectly suited for a career as a Waste Management Specialist. A specialist, mind you, not just a dabbler. Congratulations!\"",
		SKILL_EXPLOSIVES,
		0
	},
	{
		"Vault loyalty inspector",
		"\"Huh. \"Vault Loyalty Inspector\"... I thought that had been phased out decades ago. Well, sounds like a job right up your alley, hmm?\"",
		SKILL_LOCKPICK,
		0
	},
	{
		"Clinical test subject",
		"\"Interesting. \"Clinical Test Subject\"... sounds like something you should excel at. I guess you and your dad will be working together.\"",
		SKILL_MEDICINE,
		0
	},
	{
		"Fry cook",
		"\"Looks like the diner's going to get a new Fry Cook. I'll just say this once: hold the mustard, extra pickles. Ha ha ha.\"",
		SKILL_MELEE,
		0
	},
	{
		"Jukebox technician",
		"\"Thank goodness. We're finally getting a new Jukebox Technician. That thing hasn't worked right since old Joe Palmer passed.\"",
		SKILL_REPAIR,
		0
	},
	{
		"Pip-Boy programmer",
		"\"Well, well. Pip-Boy Programmer, eh? Stanley will finally have someone to talk shop with.\"",
		SKILL_SCIENCE,
		0
	},
	{
		"Tattoo artist",
		"\"Huh. I wonder who will be brave enough to be your first customer as the vault's new Tattoo Artist? I promise it won't be me.\"",
		SKILL_SMALLGUNS,
		0
	},
	{
		"Shift supervisor",
		"\"Apparently you're management material. You're going to be trained as a Shift Supervisor. Could I be talking to the next Overseer? Stranger things have happened.\"",
		SKILL_SNEAK,
		0
	},
	{
		"Marriage counselor",
		"\"Wow. Wow. Says here you're going to be the vault's Marriage Counselor. Almost makes me want to get married, just to be able to avail myself of your services.\"",
		SKILL_SPEECH,
		0
	},
	{
		"Little league coach",
		"\"I always thought you'd have a career in professional sports. You're the new vault Little League coach! Congratulations.\"",
		SKILL_UNARMED,
		0
	}
};

#endif /* GOAT_H */