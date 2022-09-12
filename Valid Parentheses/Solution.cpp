#include "Solution.h"

#include <stack>

bool Solution::isValid(std::string s)
{
	std::stack<char> currentChars;

	currentChars.push(s[0]);

	for (size_t i = 1; i < s.length(); i++)
	{
		char currentIndex = s[i];
		if (!currentChars.empty() && 
			((currentIndex == ')' && currentChars.top() == '(') ||
			 (currentIndex == ']' && currentChars.top() == '[') ||
			 (currentIndex == '}' && currentChars.top() == '{'))
			)
		{
			currentChars.pop();
			continue;
		}
		else
		{
			currentChars.push(currentIndex);
		}
	}

	return currentChars.empty();
}


























// without order

//#include <vector>
//
//enum class State {
//	OpenRound,
//	ClosedRound,
//	OpenCurly,
//	ClosedCurly,
//	OpenSquare,
//	ClosedSquare,
//};
//
//State GetState(char c);
//bool EraseIfHasMatchingPair(State currentState, std::vector<State>& states, State state);
//
//bool Solution::isValidNoOrder(std::string s)
//{
//	std::vector<State> states;
//
//	for (size_t i = 0; i < s.length(); i++)
//	{
//		auto currentState = GetState(s[i]);
//
//		if (EraseIfHasMatchingPair(currentState, states, State::OpenCurly))
//		{
//			continue;
//		}
//
//		if (EraseIfHasMatchingPair(currentState, states, State::OpenRound))
//		{
//			continue;
//		}
//
//		if (EraseIfHasMatchingPair(currentState, states, State::OpenSquare))
//		{
//			continue;
//		}
//
//		states.push_back(currentState);
//	}
//
//	return states.empty();
//}
//
//bool EraseIfHasMatchingPair(State currentState, std::vector<State>& states, State state)
//{
//	// if current is the matching closed bracket, we check
//	if (currentState == static_cast<State>((static_cast<int>(state) + 1)))
//	{
//		// if we have a matching open, we erase
//		auto isOpen = std::find(states.begin(), states.end(), state);
//		if (isOpen != states.end())
//		{
//			states.erase(isOpen);
//			return true;
//		}
//	}
//
//	return false;
//}
//
//State GetState(char c)
//{
//	switch (c)
//	{
//		case '(':
//		{
//			return State::OpenRound;
//			break;
//		}
//		case '{':
//		{
//			return State::OpenCurly;
//			break;
//		}
//		case '[':
//		{
//			return State::OpenSquare;
//			break;
//		}
//		case ')':
//		{
//			return State::ClosedRound;
//			break;
//		}
//		case '}':
//		{
//			return State::ClosedCurly;
//			break;
//		}
//		case ']':
//		{
//			return State::ClosedSquare;
//			break;
//		}
//	default:
//		break;
//	}
//}