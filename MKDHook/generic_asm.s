# umkd assembly functions

.globl plyr_weapon_grab_direct
.globl freeze_reaction_patch
.globl freeze_reaction_patchP2
.globl cyrax_bomb_hack_check
.globl eye_gore_check
.globl eye_gore2_check
.globl eye_gore3_check
.globl scorpion_spear_launch_hack
.globl scorpion_spear_victory_hack

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
	li		$a1, 65 #SUBZERO2
	beq     $v0, $a1, 1f
	j		0x215D98

	1:
	j		0x216054



freeze_reaction_patchP2:
	li		$a1, 3 #SUBZERO
	beq     $v1, $a1, 1f
	li		$a1, 47 #FROST
	beq     $v1, $a1, 1f
	li		$a1, 65 #SUBZERO2
	beq     $v1, $a1, 1f
	j		0x215DA8

	1:
	j		0x216070


cyrax_bomb_hack_check:
	move	$a0, $v0
	jal		cyrax_bomb_check_hack_safe
	beqz    $v0, 1f
	j		0x3CFD70

	1:
	j		0x3CFDE4



eye_gore_check:
	li		$v1, 6 #ERMAC
	bne     $a0, $v1, 1f
	li		$v1, 62 #REIKO
	bne     $a0, $v1, 1f
	li		$v1, 66 #ERMAC2
	bne     $a0, $v1, 1f
	j		0x13BA90

	1:
	j		0x13BC2C
		

eye_gore2_check:
	lw      $v1, 0x54($fp)
	li		$v0, 62 #REIKO
	beq     $v1, $v0, 1f	
	li		$v0, 66 #ERMAC2
	beq     $v1, $v0, 1f	
	j		0x13C7AC

	1:
	j		0x13C7B8


eye_gore3_check:
	li		$v1, 6 #ERMAC
	beq     $a0, $v1, 1f
	li		$v1, 62 #REIKO
	beq     $a0, $v1, 1f
	li		$v1, 66 #ERMAC2
	beq     $a0, $v1, 1f
	j		0x27D954

	1:
	j		0x27D95C


scorpion_spear_launch_hack:
	li      $v1, 0 # SCORPION
	beq     $v0, $v1, 1f
	li      $v1, 64 # SCORPION2
	beq     $v0, $v1, 1f
	j		0x25E018

	1:
	j		0x25E05C

scorpion_spear_victory_hack:
	li      $v1, 0 # SCORPION
	beq     $v0, $v1, 1f
	li      $v1, 64 # SCORPION2
	beq     $v0, $v1, 1f
	j		0x25DD48

	1:
	j		0x25DD8C
