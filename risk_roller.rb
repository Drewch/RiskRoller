#!/usr/bin/env ruby

class RiskRoller
  attr_reader :attackers_dice, :defenders_dice
  MAX_ATTACKER_DICE = 3
  MAX_DEFENDER_DICE = 2

  # Class Variables
  def self.attackers=(i)
    @attackers = i
    exit if @attackers == 0 # This is if they type 'q' to quit
  end
  def self.attackers
    return @attackers
  end
  def self.defenders=(i)
    @defenders = i
    exit if @defenders == 0 # This is if they type 'q' to quit
  end
  def self.defenders
    return @defenders
  end

  # Roll the Dice for an attack
  def self.roll_dice

    # Roll Attacker Dice
    case @attackers
      when 1
        puts "You cannot attack with one attacker"
        return
      when 2..3
        @attackers_dice = Array.new(@attackers-1){rand(1..6)}
      else
        @attackers_dice = Array.new(MAX_ATTACKER_DICE){rand(1..6)}
    end

    # Roll Defender Dice
    case @defenders
      when 1
        @defenders_dice = Array.new(@defenders){rand(1..6)}
      else
        @defenders_dice = Array.new(MAX_DEFENDER_DICE){rand(1..6)}
    end

    # Sort in reverse order
    @attackers_dice = @attackers_dice.sort { |a,b| b <=> a }
    @defenders_dice = @defenders_dice.sort { |a,b| b <=> a }

    # Print the rolls out to the user
    printf "Attacker's Dice: "
    @attackers_dice.each { |x| printf "%d ", x }
    puts # New line

    printf "Defender's Dice: "
    @defenders_dice.each { |x| printf "%d ", x }
    puts # New Line

    # Begin the fight
    battle

  end

  def self.battle

    # Compare the top 2 dice against each other, and take appropriate action
    for i in (0...[@defenders_dice.length,@attackers_dice.length].min)
      if @attackers_dice[i] > @defenders_dice[i]
        @defenders -= 1
      else
        @attackers -= 1
      end
    end

    puts "There are now #{@attackers} attackers and #{@defenders} defenders left"

  end

end

# Play Risk!
puts "Welcome to Risk Roller!\n\n"

begin
  puts "New Battle Beginning! (type 'q' to quit)\n\n"
  puts "How many Attackers are there?"
  RiskRoller.attackers = gets.chomp.to_i
  puts "How many Defenders are there?"
  RiskRoller.defenders = gets.chomp.to_i
  puts "There are #{RiskRoller.attackers} attackers and #{RiskRoller.defenders} defenders\n\n"
  RiskRoller.roll_dice

  while input = gets.chomp
    exit if input == "q" || input == "quit"
    break if input == "e" || input == "exit"
    RiskRoller.roll_dice
    (puts "Defender Wins! Attackers: #{RiskRoller.attackers} Defenders: #{RiskRoller.defenders}\n\n"; break) if RiskRoller.attackers < 2
    (puts "Attacker Wins! Attackers: #{RiskRoller.attackers} Defenders: #{RiskRoller.defenders}\n\n"; break) if RiskRoller.defenders < 1
  end

end while 1
