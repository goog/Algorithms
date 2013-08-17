#There are two states,"Healthy" and "Fever", but the doctor cannot observe them directly
#HMM imply the states by observes.

states = ('Rainy', 'Sunny')
 
observations = ('walk', 'shop', 'clean', 'shop', 'walk')
#observations = ['walk', 'shop'],
#use the tuples.
 
start_probability = {'Rainy': 0.6, 'Sunny': 0.4}
 
transition_probability = {
   'Rainy' : {'Rainy': 0.7, 'Sunny': 0.3},
   'Sunny' : {'Rainy': 0.4, 'Sunny': 0.6},
   }
 
emission_probability = {
   'Rainy' : {'walk': 0.1, 'shop': 0.4, 'clean': 0.5},
   'Sunny' : {'walk': 0.6, 'shop': 0.3, 'clean': 0.1},
   }

# Helps visualize the steps of Viterbi.
def print_dptable(V):
    #print 'The v is :',V  # probability columns
    print "    ",
    for i in range(len(V)): print "%7s" % ("%d" % i),
    print
 
    for y in V[0].keys():
        print "%.5s: " % y,
        for t in range(len(V)):
            print "%.7s" % ("%f" % V[t][y]),
        print
 
def viterbi(obs, states, start_p, trans_p, emit_p):
    # V is the lattice. v[t][y]: prob of being in state y at observation o in position t;
    V = [{}]
    
    # temp path
    path = {}
 
    # Initialize base cases (t == 0), calculate the step one;
    for y in states:
        V[0][y] = start_p[y] * emit_p[y][obs[0]]
        path[y] = [y]
    #print 'step 1: path is %s ' %(path)
 
    # Run Viterbi for t > 0
    for t in range(1,len(obs)):
        V.append({})
        newpath = {}
 
        for y in states:
            # Compute prob that y0 (every other state) was the previous state if y is 
            # the end state,
            #given prob of being in state y0, prob of trans from y0 to y,
            #and prob that state y emits observation that we're on
            coll = [(V[t-1][y0] * trans_p[y0][y] * emit_p[y][obs[t]], y0) for y0 in states]
            #pick the most likely previous state,max coll is the max probility to y state.
            (prob, state) = max(coll) # the state is the recorded arg Max for the current y.
            V[t][y] = prob      # the prob of being in this state is the prob of the most likely entity above
            # the most likely path to this state is the most likely path to our most likely previous state
            # plus this state , the list can add.
            newpath[y] = path[state] + [y] 
 
        # the length of path is growing.
        path = newpath
 
    print_dptable(V)
    coll = [(V[len(obs) - 1][y], y) for y in states]
    (prob, state) = max(coll)
    return (prob, path[state])

def example():
    return viterbi(observations,
                   states,
                   start_probability,
                   transition_probability,
                   emission_probability)
print example()
