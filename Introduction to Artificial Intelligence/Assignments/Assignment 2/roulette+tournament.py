import gymnasium as gym
import numpy as np
import random
import matplotlib.pyplot as plt
import copy

def evalfitness(chromosome, render_mode=None):
    env = gym.make("HalfCheetah-v5", render_mode=render_mode) 
    observation, info = env.reset()
    episode_reward = 0
    terminated = False
    truncated = False
    keyframe_index = 0
    K = len(chromosome) 
    remaining_steps = int(chromosome[keyframe_index][-1])
    while not (terminated or truncated):
        action = chromosome[keyframe_index][:-1]
        observation, reward, terminated, truncated, info = env.step(action)
        episode_reward += reward
        remaining_steps -= 1
        if remaining_steps <= 0:
            keyframe_index = (keyframe_index + 1) % K
            remaining_steps = int(chromosome[keyframe_index][-1])
    env.close()
    return episode_reward

def initPopulation(populationSize, numKeyframes):
    population = []
    for _ in range(populationSize):
        chromosome = []
        for _ in range(numKeyframes):
            torques = np.random.uniform(-1.0, 1.0, 6)
            duration = np.random.randint(5, 51)
            gene = np.append(torques, duration)
            chromosome.append(gene)
        population.append(chromosome)
    return population

def tourneySelection(population, fitnessScores):
    parentA, parentB = random.sample(range(len(population)), 2)
    if fitnessScores[parentA] > fitnessScores[parentB]:
        return population[parentA]
    else:
        return population[parentB]

def truncationSelection(pool, scores, numSelections):
    sortedPool = sorted(zip(pool, scores), key=lambda x: x[1], reverse=True)
    selected = [indiv for indiv, score in sortedPool[:numSelections]]
    selectedScores = [score for indiv, score in sortedPool[:numSelections]]
    return selected, selectedScores

def rouletteSelection(pool, scores, numSelections, replace=False):
    minScore = min(scores)
    shiftedScores = [s - minScore + 1e-6 for s in scores]
    sumScores = sum(shiftedScores)
    probabilities = [s / sumScores for s in shiftedScores]
    selectedIndices = np.random.choice(
        len(pool), 
        size=numSelections, 
        replace=replace, 
        p=probabilities
    )
    selected = [pool[i] for i in selectedIndices]
    selectedScores = [scores[i] for i in selectedIndices]
    return selected, selectedScores

def crossover(parent1, parent2):
    K_len = len(parent1)
    cp = random.randint(1, K_len - 1)
    child = parent1[:cp] + parent2[cp:]
    return child

def mutate(chromosome, mutation_rate=0.1):
    if random.random() < mutation_rate:
        randGene = random.randint(0, len(chromosome) - 1)
        randPara = random.randint(0, 6)
        if randPara < 6:
            chromosome[randGene][randPara] = np.random.uniform(-1.0, 1.0)
        else:
            chromosome[randGene][randPara] = np.random.randint(5, 51)
    return chromosome

def main():
    populationSize = 20
    nkeyframes = 5
    numGenerations = 100
    numOffspring = 10
    
    P1 = initPopulation(populationSize, nkeyframes)
    print("Evaluating initial population (Silent)...")
    fitnessScores = [evalfitness(chrom, render_mode=None) for chrom in P1]
    print(f"Initial Scores: {fitnessScores}")
    rewardsHistory = []

    for gen in range(numGenerations):
        parents, _ = rouletteSelection(P1, fitnessScores, numOffspring * 2, replace=True)
        newChildren = []        
        for i in range(numOffspring):
            p1 = parents[2 * i]
            p2 = parents[2 * i + 1]
            child = mutate(copy.deepcopy(crossover(p1, p2)))
            newChildren.append(child) 
        childScores = [evalfitness(c, render_mode=None) for c in newChildren]
        totalPool = P1 + newChildren
        totalScores = fitnessScores + childScores
        nextGenP1 = []
        while len(nextGenP1) < populationSize:
            survivor = tourneySelection(totalPool, totalScores)
            nextGenP1.append(copy.deepcopy(survivor))
        P1 = nextGenP1
        fitnessScores = [evalfitness(chrom, render_mode=None) for chrom in P1]
        bestReward = max(fitnessScores)
        rewardsHistory.append(bestReward)
        print(f"Generation {gen}: Best Reward = {bestReward}")
    print("Optimization Complete.")

    best_idx = np.argmax(fitnessScores)
    bestCheetah = P1[best_idx]
    print("Showing the best cheetah animation...")
    evalfitness(bestCheetah, render_mode="human")

    with open("best_keyframes_roulette+tournament.txt", "w") as f:
        f.write(f"{len(bestCheetah)}\n")
        for keyframe in bestCheetah:
            line = ", ".join([f"{val:.2f}" if i < 6 else f"{int(val)}" 
                             for i, val in enumerate(keyframe)])
            f.write(line + "\n")
    print("Best keyframes saved to 'best_keyframes_roulette+tournament.txt'!")

    plt.figure(figsize=(10, 5))
    plt.plot(range(numGenerations), rewardsHistory, marker='o', color='c', linestyle='-')
    plt.title("Roulette Parents + Tournament Survivors")
    plt.xlabel("Generation")
    plt.ylabel("Best Episode Reward")
    plt.grid(True)
    plt.savefig("roulette+tournament.png")
    plt.show()
    print("Deliverable 4: Convergence plot has been generated and saved.")

if __name__ == "__main__":
    main()