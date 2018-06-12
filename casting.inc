Sub CastMemSpell(SpellToMem, int i, int ForceIt)

|####### Modified from kissassist.mac #########
        /echo in CastMem
        /echo ${SpellToMem}
       
        /if (${Debug}) /echo \atDEBUGBUFFS CastMemSpell Enter \agLine#: ${Macro.CurLine}
        /if (${Int[${SpellToMem.Length}]}==0 || ${SpellToMem.Equal[null]}) {
        
        /echo no spell


        /return

        }

        /if (${i}==0) {

            /echo No Gem

            /return

        }
            

        /if (${Int[${Me.Gem[${SpellToMem}]}]}>0 && !${ForceIt}) /return
        | Unmem a spell if already memmed in a diffent gem
        /if (${ForceIt}) {
            /if (${Int[${Me.Gem[${SpellToMem}]}]}>0 && ${i}!=${ForceIt}) {
                /notify CastSpellWnd CSPW_Spell${Int[${Math.Calc[${ForceIt}-1]}]} rightmouseup
                /delay 20 ${Int[${Me.Gem[${i}].ID}]}==0
            }
        }
        /if (${Me.Book[${SpellToMem}]}) {
            /echo in book
            /if (${Int[${Me.Gem[${i}].ID}]}>0) {
                /notify CastSpellWnd CSPW_Spell${Int[${Math.Calc[${i}-1]}]} rightmouseup
                /delay 20 ${Int[${Me.Gem[${i}].ID}]}==0
            }
            /if (!${Int[${Me.Gem[${i}].Name.Length}]} || ${Me.Gem[${i}].Name.NotEqual[${SpellToMem}]}) {
                /while (${Me.Moving}) {
                    /delay 5
                }
                /echo Meming ${SpellToMem} in slot ${i}
                /if (${Stick.Active}) {
                    /stick pause 
                    /MemSpell ${i} "${SpellToMem}"
                    /delay 90 ${Me.Gem[${i}].Name.Equal[${SpellToMem}]} 
                    /stick unpause
                } else {
                    /MemSpell ${i} "${SpellToMem}"
                    /delay 90 ${Me.Gem[${i}].Name.Equal[${SpellToMem}]} 
                }
            }
        } else {
            /echo Could Not find the spell ${SpellToMem} in your spell book.
        }
        /if (${Window[SpellBookWnd].Open}) /windowstate spellbookwnd close
        /if (${Debug}) /echo \atDEBUGBUFFS CastMemSpell ${SpellToMem} ${i} ${ForceIt} ${sentFrom} \agLine#: ${Macro.CurLine}
        /if (${Debug}) /echo \atDEBUGBUFFS CastMemSpell Leave \agLine#: ${Macro.CurLine}
    /return   

|------------------------------------------------------------------------------------------------------|

Sub CastWait(string WaitSpell)

|####### Modified from kissassist.mac #########

    
        /echo in wait
        /echo ${WaitSpell}
        /echo ${Spell[${WaitSpell}].CastTime}
        /if (${Spell[${WaitSpell}].CastTime}) {
            /echo Cast Time
            /while (${Me.Casting.ID} || ${Cast.Status.Equal[C]}) {
                /delay 5
            }
        }
    /return

|----------------------------------------------------------------------------------------------------|
Sub SpellReady(string WaitSpell)

|####### Modified from kissassist.mac #########
       
       /declare WaitTimer timer 0

       /echo ${WaitSpell}

       /echo ${Me.Gem[${WaitSpell}]}
                 
       /if (${Me.Gem[${WaitSpell}]}) {
            /varset WaitTimer 300
            /while (!${Me.SpellReady[${WaitSpell}]} && ${WaitTimer}) {
                /delay 5
            }
            }
           
    /return