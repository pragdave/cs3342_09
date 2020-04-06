var stateMachine = new Map(
    //state 0
    [0,[["the",1]]],
    //state 1
    [1,[["lazy",2],["smelly",2],["dog", 3],["cat",3]]],
    //state 2
    [2,[["lazy",2],["smelly",2],["dog", 3],["cat",3]]],
    //state 3
    [3,[["ate",4], ["ran",4]]],
    //state 4
    [4,[["EOI"],["noisily",5],["slowly",5]]], 
    //state 5
    [5,["EOI"]]
    )

function vaildSentence(sentence){
    var words = sentence.split(" ")
  for(let i = 0; i < words.length; i++){
      let currentState = stateMachine[0]
      if(currentState.has(words[0]) == false){
          return false
      }
      else{
      newStateId = currentState.get(words[i]).value
      currentState = stateMachine[newStateId]
    }
  }
  return true
}

console.log('the smelly dog ate EOI' + vaildSentence('the smelly dog ate EOI'))