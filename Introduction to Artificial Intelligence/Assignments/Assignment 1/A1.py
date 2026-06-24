import numpy as np
import heapq
from collections import deque
import time

def load_embeddings(file_path):
    embeddict = {}
    vocab = []
    vectors = []
    with open(file_path, 'r', encoding='utf-8') as f:
        for line in f:
            values = line.split()
            word = values[0]
            vector = np.asarray(values[1:], dtype='float32')
            embeddict[word] = vector
            vocab.append(word)
            vectors.append(vector)
    return embeddict, vocab, np.array(vectors)

def cosdist(u_word, v_word, embeddings):
    u = embeddings[u_word]
    v = embeddings[v_word]
    dist = 1 - np.dot(u, v) / (np.linalg.norm(u) * np.linalg.norm(v))
    return dist

def getneighbors(word, embeddings, vector_matrix, vocab, k):
    if word not in embeddings:
        return []
    targetvec = embeddings[word].reshape(1, -1)
    dotprod = np.dot(vector_matrix, targetvec.T).flatten()
    norms = np.linalg.norm(vector_matrix, axis=1) * np.linalg.norm(targetvec)
    similarity = dotprod / norms
    closestindices = np.argsort(similarity)[-(k+1):-1][::-1]
    return [vocab[i] for i in closestindices]

class Node: 
    def __init__(self, state, parent=None, pathcost=0):
        self.state = state
        self.parent = parent
        self.pathcost = pathcost

    def __lt__(self, other):
        return self.pathcost < other.pathcost

    def expand(self, problem, k):
        neighbors = getneighbors(self.state, problem.embeddings, 
                                 problem.vectormatrix, problem.vocab, k)
        return [Node(nextstate, self, self.pathcost + 1) for nextstate in neighbors]

    def path(self):
        node, pathback = self, []
        while node:
            pathback.append(node.state)
            node = node.parent
        return pathback[::-1]

class WordLadderProblem:
    def __init__(self, initial, goal, embeddings, vectormatrix, vocab):
        self.initial = initial
        self.goal = goal
        self.embeddings = embeddings
        self.vectormatrix = vectormatrix
        self.vocab = vocab

    def goal_test(self, state):
        return state == self.goal

def breadth_first_graph_search(problem, k):
    node = Node(problem.initial)
    if problem.goal_test(node.state):
        return node.path(), 1
    frontier = deque([node])
    explored = set()
    nodes_expanded = 0
    frontier_states = {node.state}
    while frontier:
        node = frontier.popleft()
        frontier_states.remove(node.state)
        nodes_expanded += 1
        explored.add(node.state)
        for child in node.expand(problem, k):
            if child.state not in explored and child.state not in frontier_states:
                if problem.goal_test(child.state):
                    return child.path(), nodes_expanded
                frontier.append(child)
                frontier_states.add(child.state)         
    return None, nodes_expanded

def depth_first_graph_search(problem, k, limit=50):
    start_node = Node(problem.initial)
    frontier = [start_node] 
    explored = set()
    nodes_expanded = 0
    while frontier:
        node = frontier.pop()
        if problem.goal_test(node.state):
            return node.path(), nodes_expanded
        if node.state not in explored:
            explored.add(node.state)
            nodes_expanded += 1
            if node.pathcost < limit:
                for child in node.expand(problem, k):
                    if child.state not in explored:
                        frontier.append(child)        
    return None, nodes_expanded

def uniform_cost_search(problem, k):
    node = Node(problem.initial, pathcost=0)
    frontier = []
    count = 0 
    heapq.heappush(frontier, (node.pathcost, count, node))
    explored = set()
    nodes_expanded = 0
    while frontier:
        cost, _, node = heapq.heappop(frontier)
        if problem.goal_test(node.state):
            return node.path(), nodes_expanded
        if node.state not in explored:
            explored.add(node.state)
            nodes_expanded += 1
            for child in node.expand(problem, k):
                if child.state not in explored:
                    count += 1
                    heapq.heappush(frontier, (child.pathcost, count, child))
    return None, nodes_expanded

def greedy_best_first_search(problem, k):
    h_start = cosdist(problem.initial, problem.goal, problem.embeddings)
    node = Node(problem.initial)
    frontier = []
    count = 0 
    heapq.heappush(frontier, (h_start, count, node))
    explored = set()
    nodes_expanded = 0
    while frontier:
        h_val, _, node = heapq.heappop(frontier)
        if problem.goal_test(node.state):
            return node.path(), nodes_expanded
        if node.state not in explored:
            explored.add(node.state)
            nodes_expanded += 1
            for child in node.expand(problem, k):
                if child.state not in explored:
                    count += 1
                    h_child = cosdist(child.state, problem.goal, problem.embeddings)
                    heapq.heappush(frontier, (h_child, count, child))
    return None, nodes_expanded

def a_star_search(problem, k):
    h_start = cosdist(problem.initial, problem.goal, problem.embeddings)
    node = Node(problem.initial, pathcost=0)
    frontier = []
    count = 0 
    heapq.heappush(frontier, (h_start, count, node)) # f = 0 + h
    explored = {}
    nodes_expanded = 0
    while frontier:
        f_score, _, node = heapq.heappop(frontier)
        if problem.goal_test(node.state):
            return node.path(), nodes_expanded
        if node.state not in explored or node.pathcost < explored[node.state]:
            explored[node.state] = node.pathcost
            nodes_expanded += 1
            for child in node.expand(problem, k):
                h_child = cosdist(child.state, problem.goal, problem.embeddings)
                f_child = child.pathcost + h_child
                if child.state not in explored or child.pathcost < explored[child.state]:
                    count += 1
                    heapq.heappush(frontier, (f_child, count, child))
    return None, nodes_expanded

if __name__ == "__main__":
    print("Loading embeddings...")
    e_dict, v_list, v_matrix = load_embeddings('glove.100d.20000.txt')
    print(f"Successfully loaded {len(e_dict)} words.")
    test_pairs = [("panah", "haloze"), ("doped", "stojic"), ("qianmen", "nurturance"), ("kazuhito", "yasunobu"), ("priebe", "gelfand")]
    k_value = 20
    algorithms = [
        ("BFS", breadth_first_graph_search),
        ("DFS", depth_first_graph_search),
        ("UCS", uniform_cost_search),
        ("Greedy", greedy_best_first_search),
        ("A*", a_star_search)
    ]
    for start_word, goal_word in test_pairs:
        if start_word not in e_dict or goal_word not in e_dict:
            missing = start_word if start_word not in e_dict else goal_word
            print(f"\nSkipping: '{missing}' is not in the vocabulary.")
            continue
        print(f"\n" + "="*50)
        print(f"WORD LADDER: {start_word.upper()} -> {goal_word.upper()}")
        print("="*50)
        print(f"{'Algorithm':<10} | {'Nodes':<8} | {'Time (s)':<10} | {'Length':<8}")
        print("-" * 45)
        prob = WordLadderProblem(start_word, goal_word, e_dict, v_matrix, v_list)
        for name, func in algorithms:
            start_time = time.time()
            path, expanded = func(prob, k_value)
            end_time = time.time()
            duration = end_time - start_time
            path_len = len(path) if path else "N/A"
            print(f"{name:<10} | {expanded:<8} | {duration:<10.4f} | {path_len:<8}")
            if path and name in ["A*", "BFS", "DFS", "UCS", "Greedy"]:
                print(f"  Path: {' -> '.join(path)}")