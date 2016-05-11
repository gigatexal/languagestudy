verbs = 0;
adjectives = 0;
nouns = 0;

with open('story.txt') as story:
   for words in story:
      for word in words.split():
         words_list = ['verb','adjective','noun'];
            if 'verb' in word_list: verbs+=1
            if "adjective" in words_list: adjectives+=1;
            if "nouns" in words_list_verbs: nouns+1


print (verbs,adjectives,nouns)   
