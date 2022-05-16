#pragma once
#include "abstruction_level.h"
#include "and_gate.h"
#include "or_gate.h"
#include "xor_gate.h"

class gate_level : public abstruction_level
{
public:
	void Initialize();
	void Update();
	void Draw(sf::RenderWindow* window);
	void Destroy();

private:
	xor_gate* xor_adder_first_sum;
	xor_gate* xor_adder_second_sum;
	xor_gate* xor_adder_second_sum_bit;
	and_gate* and_adder_first_carry;
	and_gate* and_adder_both_carrys;
	and_gate* and_adder_second_carry;
	or_gate* or_adder_second_carry;

	wire* A_adder_zero;
	wire* A_adder_one;
	wire* B_adder_zero;
	wire* B_adder_one;

	wire* S_adder_zero;
	wire* first_adder_carry;
	wire* S_adder_pre_one;
	wire* S_adder_one;
	wire* S_adder_pre_carry;
	wire* S_adder_pre2_carry;
	wire* S_adder_carry;


	and_gate* and_decoder_one;
	and_gate* and_decoder_two;
	and_gate* and_decoder_three;
	and_gate* and_decoder_four;

	wire* A_decoder;
	wire* B_decoder;

	wire* S_decoder_one;
	wire* S_decoder_two;
	wire* S_decoder_three;
	wire* S_decoder_four;


	and_gate* and_mux_zero;
	and_gate* and_mux_one;
	or_gate* or_mux;

	wire* A_mux;
	wire* B_mux;
	wire* I_mux;

	wire* S_mux_pre_zero;
	wire* S_mux_pre_one;
	wire* S_mux;
};

