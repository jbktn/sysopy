#!/bin/bash

convert $1 $2 -geometry +$3+$4 -composite out.pdf
evince out.pdf