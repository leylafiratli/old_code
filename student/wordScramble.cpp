  while ( !wordGuessed && numTurns > 0 ){
    cout << "The scrambled word is: " <<scrambledWord<<endl;
  cout << "make a guess:";
  cin>>guess;

  if (!strcmp ( guess, wordBank[target] ) 
	{
	wordGuessed = true;
	}

  numTurns--;

  }
  if(wordGuessed){
    cout << "You win!" << endl;
  }
  else {
    cout << "Too many turns...You lose!" << endl;
  }
    
  return 0;
}
