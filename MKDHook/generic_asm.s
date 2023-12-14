# umkd assembly functions

.globl plyr_weapon_grab_direct
.globl freeze_reaction_patch
.globl freeze_reaction_patchP2


plyr_weapon_grab_direct:
	addiu   $sp, -32
    
	sd      $ra, 16($sp)
	lw      $a3, 0($a1)     
	lw      $v1, 92($a3)
	li      $v0, 1
	addiu   $a2, $a1, 16     
	sd      $v0, 0($sp)      
	addiu   $a5, $v1, 12     
	lw      $a4, 8($v1)      
	addiu   $a6, $v1, 24     
	addiu   $a7, $v1, 36   
	jal     0x228580

	ld      $ra, 16($sp)
	jr      $ra
	addiu   $sp, 32


# for some reason on ps2 frost freeze functions are delayed

freeze_reaction_patch:
	li		$a1, 3 #SUBZERO
	beq     $v0, $a1, 1f
	li		$a1, 47 #FROST
	beq     $v0, $a1, 1f
	j		0x215D98

	1:
	j		0x216054



freeze_reaction_patchP2:
	li		$a1, 3 #SUBZERO
	beq     $v1, $a1, 1f
	li		$a1, 47 #FROST
	beq     $v1, $a1, 1f
	j		0x215DA8

	1:
	j		0x216070
