/*

This challenge is a slightly different kind of Code Golf challenge. Rather than coding to match IO, you code to match an interface.

Background

Finite state machines are very useful design models for modeling event-based programming.
A state machine is defined by a set of states and tranitions between them.
The machine can be in one and only one state at any given time: the current state. Naturally, the machine has an initial state.
When an event occurs, it may change it's state to another state; this is called a transition.
A Moore machine is simply a FSM which can produce output; each state can produce an output.

For example, consider the following state machine which models a turnstile:

Image of a turnstile Basic state machine example

The Locked state is the initial state of the machine. Whenever the turnstile is Pushed from this state, we do nothing (go back to the Locked state).
However, if we receive a Coin, we transition to the Un-locked state. Extra Coins do nothing, but a Push puts us back into the Locked state.
It's not explicitly stated, but this FSM does have output: the Locked state has an output that tells the turnstile to lock it's arms, wheras the Un-locked state has an output that allows the turnstile to turn.

Task
You must implement a state machine class. This means that only languages with objects can compete.
If there is an accepted alternative to objects in your language, that is valid (e.g. C can use structs with member functions).
You must be able to access the functions of the object via obj.function or obj->function or whatever the accessor character for your language is.
You are allowed to use a state machine library if it exists for your language, but you aren't allowed to use a class from the library "as your own" (don't just point at a premade class and say that that's your solution).

You must implement the following methods with exactly the specified names and signatures. However, you may capitalize the first letter or switch to snake_case (e.g. mapOutput, MapOutput, or map_output are all valid).
Additionally, you may take an explicit this parameter as the first parameter:

map(State from, Event event, State to) Defines a transition from from to to on the event event. If from and event have both been previously passed to this method before, you may do anything at all.
mapOutput(State state, Output output) Assigns the given output to the given state. If state has been previously passed to this method before, you may do anything at all.
processEvent(Event event) Advances the state machine according to the transitions defined via map.
                          Basically, if the current state of the state machine is from, then event sets the current state to the state defined by a previously called map(from, event, to).
                          Throws an exception or fails violently if there is no mapping for the current state and given event.
getOutput() Gets the output for the current state, as defined via mapOutput. Returns null or equivalent if there is no output defined for the given state. This may be an Optional type or similar if your language has one.

Some sort of initial-state setting. This may be done in the constructor for your class, you may require State to have a default constructor, or you may provide some other way of setting the initial state.
The idea of State, Event, and Output is that they are generic types.
You don't have to support generics per se, but this means that the user of your state machine will only pass in the type State for states, the type Event for events, and the type Output for outputs.
However, the state machine is expected to be "generic" in that it should be possible to use any type as a State, any type as an Event, and any type as an Output.

Additionally, you map implement the map and mapOutput methods in a separate builder class, but I don't foresee that saving any bytes.

Test cases
Note: don't trust my code. It's untested. It's intended mostly to give an idea of what you state machine will be used like

Java, classname StateMachine, initial-state passed via constructor:

// States are ints, Events are chars, Outputs are ints
StateMachine machine = new StateMachine(0);
machine.map(0, '0', 1);
machine.map(0, '1', 2);
machine.map(0, '2', 3);
machine.map(1, '3', 0);
machine.map(1, '4', 2);
machine.map(2, '5', 0);
machine.map(2, '6', 1);
machine.map(2, '7', 2);
machine.mapOutput(1, 1);
machine.mapOutput(2, 10);
machine.mapOutput(3, 0);

// At this point, there should be absolutely no errors at all.
System.out.println(machine.getOutput()); // Should output `null`
machine.processEvent('0'); // Don't count on reference equality here...
System.out.println(machine.getOutput()); // Should output `1`
machine.processEvent('4');
System.out.println(machine.getOutput()); // Should output `10`
machine.processEvent('7');
System.out.println(machine.getOutput()); // Should output `10`
machine.processEvent('6');
System.out.println(machine.getOutput()); // Should output `1`
machine.processEvent('3');
System.out.println(machine.getOutput()); // Should output `null`
machine.processEvent('1');
System.out.println(machine.getOutput()); // Should output `10`
machine.processEvent('5');
System.out.println(machine.getOutput()); // Should output `null`
machine.processEvent('2');
System.out.println(machine.getOutput()); // Should output `0`
// Now any calls to processEvent should cause an exception to be thrown.
machine.processEvent('0'); // Throws an exception or crashes the program.
Ruby, classname SM, initial-state through attr_writer on i:

sm = SM.new
sm.i = :init # All states will be symbols in this case.
[
  [:init, [], :init],
  [:init, [1], :state1],
  [:init, [2, 3], :state2],
  [:state1, [], :init],
  [:state1, [1], :state1],
  [:state1, [2, 3], :state2],
  [:state2, [], :init],
  [:state2, [1], :state1],
  [:state2, [2, 3], :state2]
].each { |from, trigger, to| sm.map(from, trigger, to) }
sm.mapOutput(:state1, [1])
sm.mapOutput(:state2, [[2, 3], 4, 5])

p sm.getOutput # => nil
sm.processEvent []
p sm.getOutput # => nil
sm.processEvent [1]
p sm.getOutput # => [1]
sm.processEvent [1]
p sm.getOutput # => [1]
sm.processEvent [2, 3]
p sm.getOutput # => [[2, 3], 4, 5]
sm.processEvent [2, 3]
p sm.getOutput # => [[2, 3], 4, 5]
sm.processEvent []
p sm.getOutput # => nil
sm.processEvent [2, 3]
p sm.getOutput # => [[2, 3], 4, 5]
sm.processEvent [1]
p sm.getOutput # => [1]
sm.processEvent []
p sm.getOutput # => nil

Note that even though there are only a few test cases, you must support arbitrary input to these functions.

*/

package main

func main() {
	m := NewMoore("0")
	m.Map("0", "0", "1")
	m.Map("0", "1", "2")
	m.Map("0", "2", "3")
	m.Map("1", "3", "0")
	m.Map("1", "4", "2")
	m.Map("2", "5", "0")
	m.Map("2", "6", "1")
	m.Map("2", "7", "2")
	m.Hook("1", "1")
	m.Hook("2", "10")
	m.Hook("3", "0")

	assert(m.Output() == "")
	assert(m.Process("0"))
	assert(m.Output() == "1")
	assert(m.Process("4"))
	assert(m.Output() == "10")
	assert(m.Process("7"))
	assert(m.Output() == "10")
	assert(m.Process("6"))
	assert(m.Output() == "1")
	assert(m.Process("3"))
	assert(m.Output() == "")
	assert(m.Process("1"))
	assert(m.Output() == "10")
	assert(m.Process("5"))
	assert(m.Output() == "")
	assert(m.Process("2"))
	assert(m.Output() == "0")
	assert(!m.Process("0"))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Moore struct {
	state      string
	transition map[[2]string]string
	output     map[string]string
}

func NewMoore(state string) *Moore {
	return &Moore{
		state:      state,
		transition: make(map[[2]string]string),
		output:     make(map[string]string),
	}
}

func (m *Moore) Map(from, event, to string) {
	key := [2]string{from, event}
	m.transition[key] = to
}

func (m *Moore) Hook(state, output string) {
	m.output[state] = output
}

func (m *Moore) Process(event string) bool {
	key := [2]string{m.state, event}
	if _, found := m.transition[key]; !found {
		return false
	}
	m.state = m.transition[key]
	return true
}

func (m *Moore) Output() string {
	return m.output[m.state]
}
