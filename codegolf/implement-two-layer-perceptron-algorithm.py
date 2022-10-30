#!/usr/bin/env python

"""

Train a two-layer perceptron. You will find the Wikipedia article and these lecture slides useful.

Use a sigmoid activation function for both the hidden and output layers,
σ(x)=1/(1+exp(-x))

Your function should take in a list or array of input/output pairs and an integer specifying how many training passes through the input set to make.
Both the input and output will be vectors of any convenient representation in your language. You should output or otherwise initialize a classifier function or object.

Initialize the weights randomly and to prevent overflow/underflow, normalize the weight vectors after each update.

You should handle input data vectors up to 1000 dimensions and at least 10 output dimensions. The classifier function should return a vector of the activation levels of each of the outputs.

You may assume access to implementations of all of the BLAS routines.

The MNIST database has a very large training and test set you might find useful for testing purposes.

EDIT: Example dataset.

Input and output vectors (input).

Input  Output
[0,0]   [0]
[0,1]   [1]
[1,0]   [1]
[1,1]   [0]

Your program should produce a classifier that takes in a vector of two elements and returns a vector of one element that has similar behavior as the input.

"""

import numpy as np
import torch
from torch.utils.data import DataLoader
from torch import Tensor
from torch.nn import Linear
from torch.nn import ReLU
from torch.nn import Sigmoid
from torch.nn import Module
from torch.optim import SGD
from torch.nn import BCELoss
from torch.nn.init import kaiming_uniform_
from torch.nn.init import xavier_uniform_

class Data():
    def __init__(self):
        x = np.array([[0, 0], [0, 1], [1, 0], [1, 1]], dtype=np.float32)
        y = np.array([[0], [1], [1], [0]], dtype=np.float32)
        self.x = torch.from_numpy(x)
        self.y = torch.from_numpy(y)
        self.samples = len(y)
    
    def __getitem__(self, index):
        return self.x[index], self.y[index]

    def __len__(self):
        return self.samples

class MLP(Module):
    def __init__(self, n_inputs):
        super(MLP, self).__init__()
        
        self.hidden1 = Linear(n_inputs, 10)
        kaiming_uniform_(self.hidden1.weight, nonlinearity='relu')
        self.act1 = ReLU()

        self.hidden2 = Linear(10, 1)
        xavier_uniform_(self.hidden2.weight)
        self.act2 = Sigmoid()

    def forward(self, x):
        x = self.hidden1(x)
        x = self.act1(x)

        x = self.hidden2(x)
        x = self.act2(x)

        return x

def train_model(train_dl, model):
    criterion = BCELoss()
    optimizer = SGD(model.parameters(), lr=0.01, momentum=0.9)
    for epoch in range(100):
        for i, (inputs, targets) in enumerate(train_dl):
            optimizer.zero_grad()
            yhat = model(inputs)
            loss = criterion(yhat, targets)
            loss.backward()
            optimizer.step()

# https://machinelearningmastery.com/pytorch-tutorial-develop-deep-learning-models/
def main():
    train_dl = DataLoader(Data(), shuffle=True)
    model = MLP(2)
    train_model(train_dl, model)

main()
