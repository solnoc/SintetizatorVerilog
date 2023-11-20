#include "gate_level.h"
#include <iostream>

void gate_level::Initialize()
{
	/*xor_gate* xor_adder_first_sum;
	xor_gate* xor_adder_second_sum;
	and_gate* and_adder_first_carry;
	and_gate* and_adder_both_carrys;
	and_gate* and_adder_second_carry;
	or_gate* or_adder_second_carry;

	wire* A_adder_zero;
	wire* A_adder_one;
	wire* B_adder_zero;
	wire* b_adder_one;

	wire* S_adder_zero;
	wire* first_adder_carry;
	wire* S_adder_pre_one;
	wire* S_adder_one;
	wire* S_adder_pre_carry;
	wire* S_adder_pre2_carry;
	wire* S_adder_carry;*/

	xor_adder_first_sum = new xor_gate(sf::Vector2f(30.0f, 0.0f), 0.0f, sf::Vector2f(30.0f, 30.0f));
	sf::Vertex i1 = xor_adder_first_sum->GetInputPosition(0);
	sf::Vertex i2 = xor_adder_first_sum->GetInputPosition(1);
	sf::Vertex o = xor_adder_first_sum->GetOutputPosition();
	A_adder_zero = new wire(rand() % 2);
	A_adder_zero->AddCorner(0.0f, i1.position.y);
	A_adder_zero->AddCorner(i1);
	B_adder_zero = new wire(rand() % 2);
	B_adder_zero->AddCorner(0.0f, i2.position.y);
	B_adder_zero->AddCorner(i2);
	S_adder_zero = new wire();
	S_adder_zero->AddCorner(o);
	S_adder_zero->AddCorner(100.0f, o.position.y);
	xor_adder_first_sum->SetInput(0, A_adder_zero);
	xor_adder_first_sum->SetInput(1, B_adder_zero);
	xor_adder_first_sum->SetOutput(S_adder_zero);

	and_adder_first_carry = new and_gate(sf::Vector2f(30.0f, xor_adder_first_sum->GetPosition().y + 40.0f), 0.0f, sf::Vector2f(30.0f, 30.0f));
	A_adder_zero->AddDisjoining(sf::Vector2f(i1.position.x / 3 * 2, i1.position.y));
	A_adder_zero->AddCorner(i1.position.x / 3 * 2, i1.position.y);
	B_adder_zero->AddDisjoining(sf::Vector2f(i2.position.x / 3, i2.position.y));
	B_adder_zero->AddCorner(i2.position.x / 3, i2.position.y);
	i1 = and_adder_first_carry->GetInputPosition(0);
	i2 = and_adder_first_carry->GetInputPosition(1);
	o = and_adder_first_carry->GetOutputPosition();
	A_adder_zero->AddCorner(i1.position.x / 3 * 2, i1.position.y);
	A_adder_zero->AddCrossing(sf::Vector2f(i1.position.x / 3 * 2, xor_adder_first_sum->GetInputPosition(1).position.y));
	A_adder_zero->AddCorner(i1);
	B_adder_zero->AddCorner(i2.position.x / 3, i2.position.y);
	B_adder_zero->AddCorner(i2);
	first_adder_carry = new wire();
	first_adder_carry->AddCorner(o);
	and_adder_first_carry->SetInput(0, A_adder_zero);
	and_adder_first_carry->SetInput(1, B_adder_zero);
	and_adder_first_carry->SetOutput(first_adder_carry);

	xor_adder_second_sum = new xor_gate(sf::Vector2f(and_adder_first_carry->GetPosition().x, and_adder_first_carry->GetPosition().y + 40.0f), 0.0f, sf::Vector2f(30.0f, 30.0f));
	i1 = xor_adder_second_sum->GetInputPosition(0);
	i2 = xor_adder_second_sum->GetInputPosition(1);
	o = xor_adder_second_sum->GetOutputPosition();
	A_adder_one = new wire(rand() % 2);
	A_adder_one->AddCorner(0.0f, i1.position.y);
	A_adder_one->AddCorner(i1);
	B_adder_one = new wire(rand() % 2);
	B_adder_one->AddCorner(0.0f, i2.position.y);
	B_adder_one->AddCorner(i2);
	S_adder_pre_one = new wire();
	S_adder_pre_one->AddCorner(o);
	xor_adder_second_sum->SetInput(0, A_adder_one);
	xor_adder_second_sum->SetInput(1, B_adder_one);
	xor_adder_second_sum->SetOutput(S_adder_pre_one);

	and_adder_second_carry = new and_gate(sf::Vector2f(xor_adder_second_sum->GetPosition().x, xor_adder_second_sum->GetPosition().y + 40.0f), 0.0f, sf::Vector2f(30.0f, 30.0f));
	A_adder_one->AddDisjoining(sf::Vector2f(i1.position.x / 3 * 2, i1.position.y));
	A_adder_one->AddCorner(i1.position.x / 3 * 2, i1.position.y);
	B_adder_one->AddDisjoining(sf::Vector2f(i2.position.x / 3, i2.position.y));
	B_adder_one->AddCorner(i2.position.x / 3, i2.position.y);
	i1 = and_adder_second_carry->GetInputPosition(0);
	i2 = and_adder_second_carry->GetInputPosition(1);
	o = and_adder_second_carry->GetOutputPosition();
	A_adder_one->AddCorner(i1.position.x / 3 * 2, i1.position.y);
	A_adder_one->AddCrossing(sf::Vector2f(i1.position.x / 3 * 2, xor_adder_second_sum->GetInputPosition(1).position.y));
	A_adder_one->AddCorner(i1);
	B_adder_one->AddCorner(i2.position.x / 3, i2.position.y);
	B_adder_one->AddCorner(i2);
	S_adder_pre2_carry = new wire();
	S_adder_pre2_carry->AddCorner(o);
	S_adder_pre2_carry->AddCorner(o.position.x + 30.0f, o.position.y);
	and_adder_second_carry->SetInput(0, A_adder_one);
	and_adder_second_carry->SetInput(1, B_adder_one);
	and_adder_second_carry->SetOutput(S_adder_pre2_carry);

	xor_adder_second_sum_bit = new xor_gate(sf::Vector2f(and_adder_first_carry->GetPosition().x + 80.0f, and_adder_first_carry->GetPosition().y + 20.0f), 0.0f, sf::Vector2f(30.0f, 30.0f));
	i1 = xor_adder_second_sum_bit->GetInputPosition(0);
	i2 = xor_adder_second_sum_bit->GetInputPosition(1);
	o = xor_adder_second_sum_bit->GetOutputPosition();
	sf::Vector2f corner1((i1.position.x - and_adder_first_carry->GetOutputPosition().position.x) / 3 * 2 + and_adder_first_carry->GetOutputPosition().position.x, and_adder_first_carry->GetOutputPosition().position.y);
	first_adder_carry->AddCorner(corner1);
	first_adder_carry->AddCorner(corner1.x, i1.position.y);
	first_adder_carry->AddCorner(i1);
	sf::Vector2f corner2((i2.position.x - xor_adder_second_sum->GetOutputPosition().position.x) / 3 * 2 + xor_adder_second_sum->GetOutputPosition().position.x, xor_adder_second_sum->GetOutputPosition().position.y);
	S_adder_pre_one->AddCorner(corner2);
	S_adder_pre_one->AddCorner(corner2.x, i2.position.y);
	S_adder_pre_one->AddCorner(i2);
	S_adder_one = new wire();
	S_adder_one->AddCorner(o);
	S_adder_one->AddCorner(o.position.x + 30.0f, o.position.y);
	xor_adder_second_sum_bit->SetInput(0, first_adder_carry);
	xor_adder_second_sum_bit->SetInput(1, S_adder_pre_one);
	xor_adder_second_sum_bit->SetOutput(S_adder_one);

	and_adder_both_carrys = new and_gate(sf::Vector2f(xor_adder_second_sum_bit->GetPosition().x, xor_adder_second_sum_bit->GetPosition().y + 40.0f), 0.0f, sf::Vector2f(30.0f, 30.0f));
	i1 = and_adder_both_carrys->GetInputPosition(0);
	i2 = and_adder_both_carrys->GetInputPosition(1);
	o = and_adder_both_carrys->GetOutputPosition();
	corner1 = sf::Vector2f(corner1.x - ((1.0f / 3.0f) * (corner1.x - and_adder_first_carry->GetOutputPosition().position.x)), corner1.y);
	first_adder_carry->AddDisjoining(corner1);
	first_adder_carry->AddCorner(-1, -1);
	first_adder_carry->AddCorner(corner1);
	first_adder_carry->AddCorner(corner1.x, i1.position.y);
	first_adder_carry->AddCorner(i1);
	first_adder_carry->AddCrossing(sf::Vector2f(corner1.x, corner2.y));
	corner2 = sf::Vector2f(corner2.x - (2 * (1.0f / 3.0f) * (corner2.x - xor_adder_second_sum->GetOutputPosition().position.x)), corner2.y);
	S_adder_pre_one->AddDisjoining(corner2);
	S_adder_pre_one->AddCorner(-1, -1);
	S_adder_pre_one->AddCorner(corner2);
	S_adder_pre_one->AddCorner(corner2.x,i2.position.y);
	S_adder_pre_one->AddCorner(i2);
	S_adder_pre_carry = new wire();
	S_adder_pre_carry->AddCorner(o);
	and_adder_both_carrys->SetInput(0, first_adder_carry);
	and_adder_both_carrys->SetInput(1, S_adder_pre_one);
	and_adder_both_carrys->SetOutput(S_adder_pre_carry);

	or_adder_second_carry = new or_gate(sf::Vector2f(o.position.x + 30.0f, i2.position.y), 0.0f, sf::Vector2f(30.0f, 30.0f));
	i1 = or_adder_second_carry->GetInputPosition(0);
	i2 = or_adder_second_carry->GetInputPosition(1);
	o = or_adder_second_carry->GetOutputPosition();
	S_adder_pre_carry->AddCorner(i1);
	corner2 = sf::Vector2f(i1.position.x - ((1.0f / 2.0f) * (i1.position.x - and_adder_both_carrys->GetOutputPosition().position.x)), and_adder_second_carry->GetOutputPosition().position.y);
	S_adder_pre2_carry->AddCorner(corner2);
	S_adder_pre2_carry->AddCorner(corner2.x, i2.position.y);
	S_adder_pre2_carry->AddCorner(i2);
	S_adder_carry = new wire();
	S_adder_carry->AddCorner(o);
	S_adder_carry->AddCorner(o.position.x + 30.0f, o.position.y);
	or_adder_second_carry->SetInput(0, S_adder_pre_carry);
	or_adder_second_carry->SetInput(1, S_adder_pre2_carry);
	or_adder_second_carry->SetOutput(S_adder_carry);
	

	
	and_decoder_one = new and_gate(sf::Vector2f(and_adder_second_carry->GetPosition().x, and_adder_second_carry->GetPosition().y + 80.0f), 0.0f, sf::Vector2f(30.0f, 30.0f));
	and_decoder_one->SetInvertor(0, true);
	and_decoder_one->SetInvertor(1, true);
	i1 = and_decoder_one->GetInputPosition(0);
	i2 = and_decoder_one->GetInputPosition(1);
	o = and_decoder_one->GetOutputPosition();
	A_decoder = new wire(rand() % 2);
	A_decoder->AddCorner(i1.position.x - 50.0f, i1.position.y);
	A_decoder->AddCorner(i1);
	B_decoder = new wire(rand() % 2);
	B_decoder->AddCorner(i2.position.x - 50.0f, i2.position.y);
	B_decoder->AddCorner(i2);
	S_decoder_one = new wire();
	S_decoder_one->AddCorner(o);
	S_decoder_one->AddCorner(o.position.x + 50.0f, o.position.y);
	and_decoder_one->SetInput(0, A_decoder);
	and_decoder_one->SetInput(1, B_decoder);
	and_decoder_one->SetOutput(S_decoder_one);

	and_decoder_two = new and_gate(sf::Vector2f(and_decoder_one->GetPosition().x, and_decoder_one->GetPosition().y + 40.0f), 0.0f, sf::Vector2f(30.0f, 30.0f));
	and_decoder_two->SetInvertor(1, true);
	i1 = and_decoder_two->GetInputPosition(0);
	i2 = and_decoder_two->GetInputPosition(1);
	o = and_decoder_two->GetOutputPosition();
	corner1 = sf::Vector2f(and_decoder_one->GetInputPosition(0).position.x - (50.0f / 4.0f), and_decoder_one->GetInputPosition(0).position.y);
	A_decoder->AddCorner(corner1);
	A_decoder->AddDisjoining(corner1);
	A_decoder->AddCorner(corner1.x, i1.position.y);
	A_decoder->AddCrossing(sf::Vector2f(corner1.x, and_decoder_one->GetInputPosition(1).position.y));
	A_decoder->AddCorner(i1);
	corner2 = sf::Vector2f(corner1.x - 5.0f, and_decoder_one->GetInputPosition(1).position.y);
	B_decoder->AddCorner(corner2);
	B_decoder->AddDisjoining(corner2);
	B_decoder->AddCorner(corner2.x, i2.position.y);
	B_decoder->AddCorner(i2);
	S_decoder_two = new wire();
	S_decoder_two->AddCorner(o);
	S_decoder_two->AddCorner(o.position.x + 50.0f, o.position.y);
	and_decoder_two->SetInput(0, A_decoder);
	and_decoder_two->SetInput(1, B_decoder);
	and_decoder_two->SetOutput(S_decoder_two);

	and_decoder_three = new and_gate(sf::Vector2f(and_decoder_two->GetPosition().x, and_decoder_two->GetPosition().y + 40.0f), 0.0f, sf::Vector2f(30.0f, 30.0f));
	and_decoder_three->SetInvertor(0, true);
	i1 = and_decoder_three->GetInputPosition(0);
	i2 = and_decoder_three->GetInputPosition(1);
	o = and_decoder_three->GetOutputPosition();
	A_decoder->AddCorner(-1, -1);
	B_decoder->AddCorner(-1, -1);
	corner1 = sf::Vector2f(and_decoder_one->GetInputPosition(0).position.x - (50.0f / 2.0f), and_decoder_one->GetInputPosition(0).position.y);
	A_decoder->AddCorner(corner1);
	A_decoder->AddDisjoining(corner1);
	A_decoder->AddCorner(corner1.x, i1.position.y);
	A_decoder->AddCrossing(sf::Vector2f(corner1.x, and_decoder_one->GetInputPosition(1).position.y));
	A_decoder->AddCorner(i1);
	corner2 = sf::Vector2f(corner1.x - 5.0f, and_decoder_one->GetInputPosition(1).position.y);
	B_decoder->AddCorner(corner2);
	B_decoder->AddDisjoining(corner2);
	B_decoder->AddCorner(corner2.x, i2.position.y);
	B_decoder->AddCorner(i2);
	S_decoder_three = new wire();
	S_decoder_three->AddCorner(o);
	S_decoder_three->AddCorner(o.position.x + 50.0f, o.position.y);
	and_decoder_three->SetInput(0, A_decoder);
	and_decoder_three->SetInput(1, B_decoder);
	and_decoder_three->SetOutput(S_decoder_three);

	and_decoder_four = new and_gate(sf::Vector2f(and_decoder_three->GetPosition().x, and_decoder_three->GetPosition().y + 40.0f), 0.0f, sf::Vector2f(30.0f, 30.0f));
	i1 = and_decoder_four->GetInputPosition(0);
	i2 = and_decoder_four->GetInputPosition(1);
	o = and_decoder_four->GetOutputPosition();
	A_decoder->AddCorner(-1, -1);
	B_decoder->AddCorner(-1, -1);
	corner1 = sf::Vector2f(and_decoder_one->GetInputPosition(0).position.x - ((50.0f / 4.0f) * 3.0f), and_decoder_one->GetInputPosition(0).position.y);
	A_decoder->AddCorner(corner1);
	A_decoder->AddDisjoining(corner1);
	A_decoder->AddCorner(corner1.x, i1.position.y);
	A_decoder->AddCrossing(sf::Vector2f(corner1.x, and_decoder_one->GetInputPosition(1).position.y));
	A_decoder->AddCorner(i1);
	corner2 = sf::Vector2f(corner1.x - 5.0f, and_decoder_one->GetInputPosition(1).position.y);
	B_decoder->AddCorner(corner2);
	B_decoder->AddDisjoining(corner2);
	B_decoder->AddCorner(corner2.x, i2.position.y);
	B_decoder->AddCorner(i2);
	S_decoder_four = new wire();
	S_decoder_four->AddCorner(o);
	S_decoder_four->AddCorner(o.position.x + 50.0f, o.position.y);
	and_decoder_four->SetInput(0, A_decoder);
	and_decoder_four->SetInput(1, B_decoder);
	and_decoder_four->SetOutput(S_decoder_four);


	and_mux_zero = new and_gate(sf::Vector2f(and_decoder_four->GetPosition().x, and_decoder_four->GetPosition().y + 80.0f), 0.0f, sf::Vector2f(30.0f, 30.0f));
	and_mux_zero->SetInvertor(1, true);
	A_mux = new wire(rand() % 2);
	i1 = and_mux_zero->GetInputPosition(0);
	i2 = and_mux_zero->GetInputPosition(1);
	o = and_mux_zero->GetOutputPosition();
	A_mux->AddCorner(i1.position.x - 50.0f, i1.position.y);
	A_mux->AddCorner(i1);
	I_mux = new wire(rand() % 2);
	I_mux->AddCorner(i2);
	I_mux->AddCorner(i2.position.x - 25.0f, i2.position.y);
	S_mux_pre_zero = new wire();
	S_mux_pre_zero->AddCorner(o);
	S_mux_pre_zero->AddCorner(o.position.x + 25.0f, o.position.y);
	and_mux_zero->SetInput(0, A_mux);
	and_mux_zero->SetInput(1, I_mux);
	and_mux_zero->SetOutput(S_mux_pre_zero);

	and_mux_one = new and_gate(sf::Vector2f(and_mux_zero->GetPosition().x, and_mux_zero->GetPosition().y + 40.0f), 0.0f, sf::Vector2f(30.0f, 30.0f));
	i1 = and_mux_one->GetInputPosition(0);
	i2 = and_mux_one->GetInputPosition(1);
	o = and_mux_one->GetOutputPosition();
	B_mux = new wire(rand() % 2);
	B_mux->AddCorner(i1.position.x - 50.0f, i1.position.y);
	B_mux->AddCorner(i1);
	I_mux->AddCorner(i1.position.x - 25.0f, i2.position.y);
	I_mux->AddCorner(i2);
	I_mux->AddCorner(i2.position.x - 25.0f, i2.position.y);
	I_mux->AddDisjoining(sf::Vector2f(i2.position.x - 25.0f, i2.position.y));
	I_mux->AddCorner(i2.position.x - 25.0f, i2.position.y + 25.0f);
	I_mux->AddCrossing(sf::Vector2f(i2.position.x - 25.0f, i1.position.y));
	S_mux_pre_one = new wire();
	S_mux_pre_one->AddCorner(o);
	S_mux_pre_one->AddCorner(o.position.x + 25.0f, o.position.y);
	and_mux_one->SetInput(0, B_mux);
	and_mux_one->SetInput(1, I_mux);
	and_mux_one->SetOutput(S_mux_pre_one);

	or_mux = new or_gate(sf::Vector2f(and_mux_one->GetPosition().x + 80.0f, and_mux_one->GetPosition().y - ((and_mux_one->GetPosition().y - and_mux_zero->GetPosition().y) / 2.0f)), 0.0f, sf::Vector2f(30.0f, 30.0f));
	i1 = or_mux->GetInputPosition(0);
	i2 = or_mux->GetInputPosition(1);
	o = or_mux->GetOutputPosition();
	S_mux_pre_zero->AddCorner(and_mux_zero->GetOutputPosition().position.x + 25.0f, i1.position.y);
	S_mux_pre_zero->AddCorner(i1);
	S_mux_pre_one->AddCorner(and_mux_one->GetOutputPosition().position.x + 25.0f, i2.position.y);
	S_mux_pre_one->AddCorner(i2);
	S_mux = new wire();
	S_mux->AddCorner(o);
	S_mux->AddCorner(o.position.x + 50.0f, o.position.y);
	or_mux->SetInput(0, S_mux_pre_zero);
	or_mux->SetInput(1, S_mux_pre_one);
	or_mux->SetOutput(S_mux);
}
void gate_level::Update()
{
	xor_adder_first_sum->Update();
	and_adder_first_carry->Update();
	xor_adder_second_sum->Update();
	and_adder_second_carry->Update();
	xor_adder_second_sum_bit->Update();
	and_adder_both_carrys->Update();
	or_adder_second_carry->Update();
	
	and_decoder_one->Update();
	and_decoder_two->Update();
	and_decoder_three->Update();
	and_decoder_four->Update();

	and_mux_zero->Update();
	and_mux_one->Update();
	or_mux->Update();
}
void gate_level::Draw(sf::RenderWindow* window)
{
	A_adder_zero->DrawWire(window);
	B_adder_zero->DrawWire(window);
	S_adder_zero->DrawWire(window);
	xor_adder_first_sum->Draw(window);
	and_adder_first_carry->Draw(window);
	xor_adder_second_sum->Draw(window);
	A_adder_one->DrawWire(window);
	B_adder_one->DrawWire(window);
	S_adder_pre_one->DrawWire(window);
	and_adder_second_carry->Draw(window);
	S_adder_pre2_carry->DrawWire(window);
	S_adder_one->DrawWire(window);
	xor_adder_second_sum_bit->Draw(window);
	first_adder_carry->DrawWire(window);
	and_adder_both_carrys->Draw(window);
	S_adder_pre_carry->DrawWire(window);
	S_adder_carry->DrawWire(window);
	or_adder_second_carry->Draw(window);

	A_decoder->DrawWire(window);
	B_decoder->DrawWire(window);
	S_decoder_one->DrawWire(window);
	and_decoder_one->Draw(window);
	S_decoder_two->DrawWire(window);
	and_decoder_two->Draw(window);
	S_decoder_three->DrawWire(window);
	and_decoder_three->Draw(window);
	S_decoder_four->DrawWire(window);
	and_decoder_four->Draw(window);

	A_mux->DrawWire(window);
	and_mux_zero->Draw(window);
	B_mux->DrawWire(window);
	I_mux->DrawWire(window);
	and_mux_one->Draw(window);
	S_mux_pre_zero->DrawWire(window);
	S_mux_pre_one->DrawWire(window);
	or_mux->Draw(window);
	S_mux->DrawWire(window);
}
void gate_level::Destroy()
{
	std::cout <<"ADDER : " << A_adder_zero->GetValue() << A_adder_one->GetValue() << " + " << B_adder_zero->GetValue() << B_adder_one->GetValue() << " = " <<
		S_adder_zero->GetValue() << S_adder_one->GetValue() << S_adder_carry->GetValue() << std::endl;
	std::cout << "DECODER : " << A_decoder->GetValue() << B_decoder->GetValue() << " ===> ";
	if (S_decoder_one->GetValue())
		std::cout << "FIRST SELECTED";
	if (S_decoder_two->GetValue())
		std::cout << "SECOND SELECTED";
	if (S_decoder_three->GetValue())
		std::cout << "THIRD SELECTED";
	if (S_decoder_four->GetValue())
		std::cout << "FORTH SELECTED";
	std::cout << std::endl;
	std::cout<<"MUX : " << "SELECTED = " << I_mux->GetValue()<<" FROM A = "<<A_mux->GetValue()<<" B = "<<B_mux->GetValue()<<" ===> "<<S_mux->GetValue();
	std::cout << std::endl << std::endl;
	delete xor_adder_first_sum;
	delete first_adder_carry;
	delete xor_adder_second_sum;
}